#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int& a,int& b){
    int swap=a;
    a=b;
    b=swap;
}

int partition(int arr[],int lb,int ub){
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[lb],arr[end]);
    return end;
}

int randomPartition(int arr[],int lb,int ub){
    srand(time(0));
    int randomIndex=lb+rand()%(ub-lb+1);
    
    swap(arr[randomIndex],arr[ub]);
    return partition(arr,lb,ub);

}

void quickSortRand(int arr[],int lb,int ub){
    if(lb<ub){
        int p=randomPartition(arr,lb,ub);
        quickSortRand(arr,lb,p-1);
        quickSortRand(arr,p+1,ub);
    }
}

void quickSortDE(int arr[],int lb,int ub){
    if(lb<ub){
        int p=partition(arr,lb,ub);
        quickSortDE(arr,lb,p-1);
        quickSortDE(arr,p+1,ub);
    }
}


int main(){
    int choice;
    int n;
    char ch;
    
    do{
        cout<<"\n\n\n----------------MENU-----------------";
        cout<<"\n1.Determinant Variant\n2.Randomized Varaint\n3.Exit\nEnter your choice\t";
        cin>>choice;
        
        switch(choice){
            case 1:{
                cout<<"Enter the no. of elements in the array: ";
                cin>>n;
                int arr1[n];
                for(int i=0;i<n;i++){
                    cout<<"Enter element "<<i+1<<": ";
                    cin>>arr1[i];
                }
                cout<<"\nUnsorted array: ";
                for(int i=0;i<n;i++){
                    cout<<arr1[i]<<" ";
                }
                cout<<"\nSorted array: ";
                quickSortDE(arr1,0,n-1);
                for(int i=0;i<n;i++){
                    cout<<arr1[i]<<" ";
                }
                break;
            }
            
            case 2:{
                cout<<"Enter the no. of elements in the array: ";
                cin>>n;
                int arr2[n];
                for(int i=0;i<n;i++){
                    cout<<"Enter element "<<i+1<<": ";
                    cin>>arr2[i];
                }
                cout<<"\nUnsorted array: ";
                for(int i=0;i<n;i++){
                    cout<<arr2[i]<<" ";
                }
                cout<<"\nSorted array: ";
                quickSortRand(arr2,0,n-1);
                for(int i=0;i<n;i++){
                    cout<<arr2[i]<<" ";
                }
                break;
            }
            
            case 3:
                cout<<"Program ended";
                return 1;
                break;
            
            default:
                cout<<"\nWrong choice";
                break;
        }
        
        cout<<"\n\nDo you want to continue(Y/N) ";
        cin>>ch;
        
    }while(ch=='Y' || ch=='y');
    
    cout<<"\nProgram ended";
    return 0;
    
}