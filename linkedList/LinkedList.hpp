/**
*	@author
*	@date
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	/** TODO
		Fix this method
	*/
	//instead of returning 0, just return size
	return(m_size);
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	bool isFound = false;

	/** TODO
		Fix this method
	*/
	//loops through size of list
	for(int i=0; i<m_size; i++){
		//if temp matches and a result is found
		if(temp->getValue() == value){
			//set isFound equal to true
			isFound = true;
			//break out of loop
			break;
		}
		//if not found, move onto next in list
		temp = temp->getNext();
	}

	return(isFound);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	bool isRemoved = false;

	//if LL is empty you cant remove, so if its not empty, enter this if
	if(!isEmpty()){
		//set both last and secondLast to point to front
		lastNode = m_front;
		secondintoLast = m_front;

		//These two while loops iterate through the LL until they reach the end

		//When lastNode.getNext does not equal null, set it to get next to loop through LL
		while(lastNode->getNext() != nullptr)
		{
			lastNode = lastNode->getNext();
		}
		//When secondintoLast.getNext does not equal lastNode, set it to getNext
		while(secondintoLast->getNext() != lastNode)
		{
			secondintoLast = secondintoLast->getNext();
		}
		//once the end of LL is reached,
			//secondLast.setNext is point to null
			//then delete last
			//reduce size by 1
			//set isRemoved to true
		secondintoLast->setNext(nullptr);
		delete lastNode;
		m_size--;
		isRemoved = true;
	}
	return(isRemoved);
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
