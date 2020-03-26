template <typename T>
void Heap<T>::upheap(int index)
{
	if (index > 0)
	{
		int pIndex= ((index-1)/2);
		if(m_arr[pIndex] < m_arr[index])
		{
			Patient temp= m_arr[pIndex];
			m_arr[pIndex]= m_arr[index];
			m_arr[index]= temp;
			upheap(pIndex);
		}
	}
}

template <typename T>
void Heap<T>::downheap(int index)
{
	int maxChildIndex= 0;
	if(m_heapSize > (index*2)+2)//2 children
	{
		maxChildIndex= (m_arr[(index*2)+1] > m_arr[(index*2)+2]) ? (index*2)+1 : (index*2)+2;	
	}
	else if(m_heapSize == (index*2)+2)//1 child
	{
		maxChildIndex= (index*2)+1;
	}
	else
	{
		return;
	}
	if(m_arr[maxChildIndex] > m_arr[index])
	{
		Patient temp= m_arr[maxChildIndex];
		m_arr[maxChildIndex]= m_arr[index];
		m_arr[index]= temp;
		downheap(maxChildIndex);
	}
}

template <typename T>
Heap<T>::Heap()
{
	m_arr= nullptr;
	m_size= 0;
	m_heapSize= 0;
}

template <typename T>
Heap<T>::~Heap()
{
	clear();
}

template <typename T>
bool Heap<T>::isEmpty() const
{
	return(m_heapSize == 0);
}

template <typename T>
void Heap<T>::resize()
{
	T* tempArr= nullptr;
	m_size= (((m_size+1)*2)-1);
	tempArr= new T[m_size];
	for(int i=0; i<m_heapSize; i++)
	{
		tempArr[i]= m_arr[i];
	}
	delete[] m_arr;
	m_arr= tempArr;
}

template <typename T>
int Heap<T>::getNumberOfNodes() const
{
	return m_heapSize;
}

template <typename T>
int Heap<T>::getHeight() const
{
	
}

template <typename T>
T Heap<T>::peekTop() const
{
	return(m_arr[0]);
}

template <typename T>
void Heap<T>::add(T data)
{	
	if(m_size == m_heapSize)
	{
		resize();
	}
	m_arr[m_heapSize]= data;
	upheap(m_heapSize);
	m_heapSize++;
}

template <typename T>
void Heap<T>::remove()
{
	if(isEmpty() == false)
	{
		std::swap(m_arr[0], m_arr[m_heapSize-1]);
		m_heapSize--;
		downheap(0);
	}
	else
	{
		throw std::runtime_error("Remove attempted on an empty heap!\n");
	}
}

template <typename T>
void Heap<T>::clear()
{
	delete[] m_arr;
}

