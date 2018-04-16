#define DYNAMIC_ARRAY_CHUNK_SIZE 5
#define DYNAMIC_ARRAY_INITIAL_CAPACITY 5
class DynamicArray
{
private:
	
	void increaseCapacity()
	{
		mCapacity += DYNAMIC_ARRAY_CHUNK_SIZE;
		aux = new int[mCapacity];
		for (int i = 0; i < mSize; ++i)
		{
			aux[i] = mArray[i];
		}
		delete[] mArray;
		mArray = aux;
	}

	int *aux = nullptr;
	int *mArray = nullptr;
	unsigned int mCapacity;
	unsigned int mSize;

public:

	DynamicArray()
	{
		mArray = new int[DYNAMIC_ARRAY_CHUNK_SIZE];
		mCapacity = DYNAMIC_ARRAY_INITIAL_CAPACITY;
		mSize = 0;
	}

	~DynamicArray()
	{
		delete[] mArray;
	}

	bool empty() const
	{
		if (mSize == 0) return true;
		else return false;
	}

	unsigned int size() const { return mSize; }

	int &operator[](unsigned int index)
	{

	}

	const int &operator[](unsigned int index) const
	{

	}

	void push_back(int value)
	{
		if (mSize < mCapacity)
		{
			mArray[mSize] = value;
			mSize++;
		}

		else if (mSize == mCapacity)
		{
			increaseCapacity();
			mArray[mSize] = value;
			mSize++;
		}
	}

	void push_front(int value)
	{
		if (mSize < mCapacity)
		{
			for (int i = mSize - 1; i >= 0; --i)
			{
				mArray[i] = mArray[i--];
			}
			mArray[0] = value;
			mSize++;
		}

		else if (mSize == mCapacity)
		{
			increaseCapacity();
			for (int i = mSize - 1; i >= 0; --i)
			{
				mArray[i] = mArray[i--];
			}
			mArray[0] = value;
			mSize++;
		}
	}

	void insert(unsigned int index, int value)
	{
		if (mSize < mCapacity)
		{
			for (int i = mSize; i >= index; --i)
			{
				mArray[i] = mArray[i--];
			}
			mArray[index] = value;
			mSize++;
		}

		else if (mSize == mCapacity)
		{
			increaseCapacity();
			for (int i = mSize; i >= index; --i)
			{
				mArray[i] = mArray[i--];
			}
			mArray[index] = value;
			mSize++;
		}
	}

	void erase(unsigned int index)
	{
		for (int i = index; i < mSize; ++i)
		{
			mArray[i] = mArray[i++];
		}
		mSize--;
	}

	void clear() { mSize = 0; }
	void shrink_to_fit();

};