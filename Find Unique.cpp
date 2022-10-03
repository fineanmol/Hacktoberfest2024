//codestudio.390 Find Unique
//https://www.codingninjas.com/codestudio/problems/find-unique_625159
//Bit Manupulation

int findUnique(int *arr, int size){
    int key = 0;
    for(int i=0;i<size;i++){
        key ^= arr[i];
    }
    return key;
}
