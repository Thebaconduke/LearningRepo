#pragma once
using namespace std;

//define logging

template<class T>
class pgLinkList
{
private:
	template<class T>
	class pgNode
	{
	public:
		pgNode(T data) { m_data = data; }

		void setPointer(pgNode* pointer) { m_pointer = pointer; }

		pgNode* getPointer() { return m_pointer; }

		void setData(T data) { m_data = data; }

		T getData() { return m_data; }

		T m_data;
		pgNode* m_pointer;
	};

public:
	friend pgNode;
	void add(T data)
	{
		pgNode<T>* nextNode = new pgNode<T>(data);
		if (m_head == nullptr)
		{
			m_head = nextNode;
			return;
		}

		pgNode<T>* findNode = m_head;
		while (findNode->getPointer() != nullptr)
		{
			findNode = findNode->getPointer();
		}
		findNode->setPointer(nextNode);
	}

	T find(int index)
	{
		pgNode<T>* findNode = m_head;
		int currentCount = 0;
		while (findNode != nullptr)
		{
			if (currentCount == index)
			{
				return findNode->getData();
			}
			findNode = findNode->getPointer();
			currentCount++;
		}
		return {};
	}
	
	template<typename L>
	void sort(L& lambda) 
	{
		int totalCount = total();
		int count = 0;
		
		pgNode<T>* MaxNode = nullptr;
		while(count < totalCount)
		{
			pgNode<T>* findNode = m_head;
			pgNode<T>* nextNode = findNode->getPointer();
			while (nextNode != MaxNode)
			{
				if(lambda(findNode->getData(), nextNode->getData()))
					swap(findNode, nextNode);
				findNode = nextNode;
				nextNode = nextNode->getPointer();
			}
			MaxNode = findNode;
			count++;
		}
	}

	auto sort()
	{
		auto x = [](T a, T b)
		{
			return a > b;
		};
		sort(x);
	}

	void swap(pgNode<T>*& firstNode, pgNode<T>*& nextNode)
	{
		pgNode<T>* prevNode = m_head;
#ifdef logging 
		cout << firstNode << " -> " << firstNode->getPointer() << endl;
		cout << nextNode << " -> " << nextNode->getPointer() << endl;
#endif
		if (prevNode == firstNode)
		{
			pgNode<T>* temp = nextNode->getPointer();
			nextNode->setPointer(firstNode);
			firstNode->setPointer(temp);
			m_head = nextNode;
#ifdef logging 
			cout << firstNode << " -> " << firstNode->getPointer() << endl;
			cout << nextNode << " -> " << nextNode->getPointer() << endl;
#endif
			return;
		}
		while(prevNode->getPointer() != firstNode && prevNode->getPointer())
		{
			prevNode = prevNode->getPointer();
		}
		pgNode<T>* tempNode = nextNode->getPointer();
		prevNode->setPointer(nextNode);
		nextNode->setPointer(firstNode);
		firstNode->setPointer(tempNode);
#ifdef logging 
		cout << firstNode << " -> " << firstNode->getPointer() << endl;
		cout << nextNode << " -> " << nextNode->getPointer() << endl;
#endif
	}

	T operator[](int i) { return find(i); }

	const T operator[](int index) const { return find(index); }

	void remove(int index)
	{
		pgNode<T>* findNode = nullptr;
		pgNode<T>* prevNode = nullptr;
		findCurrentAndPrev(index, findNode, prevNode);
		prevNode->setPointer(findNode->getPointer());
		delete findNode;
	}

	void addToStart(T data)
	{
		pgNode<T>* firstNode = m_head;
		pgNode<T>* newNode = new pgNode<T>(data);
		newNode->setPointer(firstNode);
		m_head = newNode;
	} 

	int total()
	{
		int total = 0;
		pgNode<T>* totalval = m_head;
		while (totalval != nullptr)
		{
			total++;
			totalval = totalval->getPointer();
		}
		return total;
	}

	void __toString()
	{
		pgNode<T>* currentNode = m_head;
		while (currentNode)
		{
			cout << currentNode->getData() << endl;
			currentNode = currentNode->getPointer();
		}
	}

private:
	void findCurrentAndPrev(int index, pgNode<T>*& findNode, pgNode<T>*& prevNode)
	{
		pgNode<T>* fNode = m_head;
		pgNode<T>* pNode = m_head;
		int currentCount = 0;
		while (fNode != nullptr)
		{
			if (currentCount == index)
			{
				break;
			}
			pNode = fNode;
			fNode = fNode->getPointer();
			currentCount++;
		}
		prevNode = pNode;
		findNode = fNode;
	}
	pgNode<T>* m_head = nullptr;
};