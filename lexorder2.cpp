#include <iostream>
#include <cstdio>

using namespace std;

int main () {


   int nLists = 10;          
   int nElements = 10;    
   int *List[nLists];    
   int Elements[nLists]; /* Listedeki array'lerin b�y�kl�klerini tutacak */

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
    * Selection sort yapt�m:
    * E�er swap olursa hem listedeki array'lerin yeri de�i�iyor hem de array b�y�kl���n� tutan dizideki b�y�kl�klerinin yeri de�i�iyor. 
    */
   for (int i=0; i<nLists-1; i++)
   {
     
     int firstIndex = i; // ilk array'in yerinin do�ru oldu�unu farzettik.
     int firstSize = Elements[i];

 
     int nextSize;
     bool shouldSwap = false;
     int j;
     
	 // �imdi geri kalan array'ler i�inde en k���k array'i bulmaya �al��aca��z. 
     for (j=i+1; j<nLists; j++) // geri kalan� aras�nda kar��la�t�rma yapaca��m�z i�in i+1'den ba�latt�m. 
     {
       // next = List[j];
       nextSize = Elements[j];
       int limit = 0;
       // hangisinin elemen sayisi kucukse loop o kadar d�necek
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
