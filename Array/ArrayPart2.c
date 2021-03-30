/*1. Write a function that returns the number of even elements of a one-dimensional integer array.
2. Write a function that returns the value of the minimum element of a one-dimensional integer
array.
3. Write a function that returns the position (index) of the maximum element to one-dimensional
integer array.
4. Two ordered arrays a [N] and b [N] are given, where N is a natural number not greater than 20.
combine these arrays into a new array, also ordered.
5. Write a function that checks (returns 1) if all elements of a one-dimensional array are
positive or 0 otherwise.
6. Write a function that checks if there are elements with zero value in a one-dimensional array*/



//1
int evenNum(int *arr, int size){
        int i, num=0;
        for (i=0; i<size;i++)
        { 
                if (arr[i]%2==0)
                {
                           num++;
                  }
           }
           return num;
}




//2
int minimalNumberInArray(int* x, int size)
{
	int i;

	int minimalValue = *x; //x[0]

	for (i = 1; i < size; i++)
	{
		if (minimalValue < x[i])
		{
			minimalValue = x[i];
		}
	}
	return minimalValue;
}


//3
int masiv1(int* arr, int size)
{
	int i;

	int maxValue = *arr; //x[0]
	int IndexOfGreatest = 0;

	for (i = 1; i < size; i++)
	{
		if (maxValue < arr[i])
		{
			maxValue = arr[i];
			IndexOfGreatest = i;
		}
	}
	return IndexOfGreatest;
}
        

//4


void Array(int* a, int* b, int* result)
{
	int i = 0;
	int j = 0;

	while (1)
	{
		if (a[i] < b[j])
		{
			*result = a[i];
			result++;
			i++;
			if (i == N)
			{
				for (;j < N; j++)
				{
					*result = b[j];
					result++;
				}
				return;
			}
		}
		else
		{
			*result = b[j];
			result++;
			j++;
			if (j == N)
			{
				for (;i < N; i++)
				{
					*result = a[i];
					result++;
				}
				return;
			}
		}
	}
}



//5

int massif(double* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (arr[i] <= 0.0)
		{
			return 0;
		}
	}
	return 1;
}

//6

int Array(double* a, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (a[i] == 0.0)
		{
			return 1;
		}
	}
	return 0;
}


