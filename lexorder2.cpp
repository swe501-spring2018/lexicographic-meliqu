#include <iostream>
#include <cstdio>

using namespace std;

int main () {


   int nLists = 10;          
   int nElements = 10;    
   int *List[nLists];    
   int Elements[nLists]; /* Listedeki array'lerin büyüklüklerini tutacak */

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

   /**
    * Selection sort yaptým:
    * Eðer swap olursa hem listedeki array'lerin yeri deðiþiyor hem de array büyüklüðünü tutan dizideki büyüklüklerinin yeri deðiþiyor. 
    */
   for (int i=0; i<nLists-1; i++)
   {
     
     int firstIndex = i; // ilk array'in yerinin doðru olduðunu farzettik.
     int firstSize = Elements[i];

 
     int nextSize;
     bool shouldSwap = false;
     int j;
     
	 // þimdi geri kalan array'ler içinde en küçük array'i bulmaya çalýþacaðýz. 
     for (j=i+1; j<nLists; j++) // geri kalaný arasýnda karþýlaþtýrma yapacaðýmýz için i+1'den baþlattým. 
     {
       // next = List[j];
       nextSize = Elements[j];
       int limit = 0;
       // hangisinin elemen sayisi kucukse loop o kadar dönecek
       if (firstSize > nextSize) {
         limit = nextSize;
       } else {
         limit = firstSize;
       }
       for (int k=0; k<limit; k++)
       {
         if (List[j][k] < List[firstIndex][k]) { /* karsilastirdigimiz 
eleman daha kucuk ise first arrayin index ini degistiriyoruz */
           firstIndex = j;
           firstSize = nextSize;
           shouldSwap = true;
           break;
         } else if (List[j][k] > List[firstIndex][k]) { /* buyuk ise geri 
kalanlarina bakmamiza gerek yok */
           break;
         } else { // esit durumu kaliyor, esitlik bozulmadigi icin bakmaya devam

           continue;
         }
       }
     } // ikinci loopun sonu
     // we may not need to do swapping
     if (shouldSwap == true)
     {
       // swap list in list of list
       int *tempList = List[i];
       List[i] = List[firstIndex];
       List[firstIndex] = tempList;
       // swap size in list of size
       int temp = Elements[i];
       Elements[i] = firstSize;
       Elements[firstIndex] = temp;
     }
   }

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
