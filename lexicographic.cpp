#include <iostream>
#include <cstdio>

using namespace std;

 
	
	void swap (int xp, int yp)
	
	{
		int temp = xp;
		xp = yp;
		yp = temp;
		
	}
	
	bool shouldswap(int a,int b)
	{
		bool result = false;
		if(a>b)
		{
			result = true;
		}
		else if(a>b)
		{
			result = false;
		}
		else if (a==b)
		{
			result = false;
		}
		return result;
	}
	
	
	void sort (int *List[], int size)
	
	{
		
		for (int i = 0; i<size-1; i++) 
		{
			if (shouldswap(List[i][0], List[i+1][0]))
			{
					swap(List[i],List[i+1]);
					
			}
		}
	} 

	int main () { 
	
	
	int nLists;
    int nElements;
    int *List[nLists];
    int Elements[nLists]; 
    
    cin >> nLists;   
 
    
    for (int i=0; i<nLists; i++) {

		cin >> nElements;		
		 	
    	List[i] = new int[nElements];  
    	
    	for (int j=0; j<nElements; j++) {
    		
    		cin >> List[i][j];
			
			Elements[i] = nElements;	
				
		}				
	} 
	
	
	cout << "original values" << endl;
	
	for (int i=0; i<nLists; i++) 
	{
	
		int count = Elements[i];		
		
		for (int j=0; j<count; j++) 
		{		
		cout << List[i][j] << " "; 		
		}
		
		cout << endl;
	} 
	
		sort(List,nLists);
		
		cout << "sorted values" << endl;
		
		for (int i=0; i<nLists; i++) 
		{
	
		
			
		int count = Elements[i];
		
				
		for (int j=0; j<count; j++) 
		{		
		cout << List[i][j] << " "; 			
		}
		
		cout << endl;	
	
		}
		
	return 0;
	
	
}


	
	


