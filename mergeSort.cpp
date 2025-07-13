#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std ;

void merge ( int arr [],int s , int mid , int e){
    int left =s ; 
    int right = mid +1 ; 
    vector < int > temp ; 
    
    while ( left <= mid  && right <=e ) {
        if ( arr[left] <= arr[right]) {
            temp.push_back(arr[left++])  ; 
        }
        else {
            temp.push_back(arr[right++]) ; 
        }
    }
    while ( left <= mid ) {
         temp.push_back(arr[left++])  ; 
    }
    while ( right <= e ) {
         temp.push_back(arr[right++])  ; 
    }
   for ( int i = 0 ; i < temp.size() ; i++ ) {
    arr[i+s] = temp[i] ;
   }
}

void mergeSort ( int arr[] , int s , int e ) {
    if ( s >= e )
    return ;    
    int mid = (s+e)/2 ; 

    mergeSort ( arr , s ,mid  ) ;
    mergeSort ( arr , mid +1 , e ) ; 
    merge( arr , s , mid , e ) ; 
}

int main () {

     int arr [] = { 3,1,4,7,53,23,6,676,43,65,2,243,5} ; 
     mergeSort ( arr , 0 , 12  ) ;
     for ( int i : arr)
     cout << i << " " ;

return 0 ;
}