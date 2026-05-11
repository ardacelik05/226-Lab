#include <iostream>
using namespace std;

class Points {
public: int x;
};

void swapValues(int *p1, int *p2) {
    int temp= *p1;
    *p1 = *p2;
    *p2 = temp;
}

void printArray(Points* arr, int size) {
    for (int n=0;n<size;n++) {
        cout<<arr[n].x<<" ";
    }
    cout<<endl;
}

int findSum(Points* arr, int size) {
    int sum=0;
    for (int n=0;n<size;n++) {
        sum += (arr+n)->x;
    }
    return sum;
}

Points* createArray(int size) {
    return new Points[size];
}

void deleteArray(Points* arr) {
    delete[] arr;
    cout << "Memory released successfully." << endl;
}

void shiftRight(Points* arr,int size) {
    if (size<=1) return;
    int lastVal = (arr + size - 1)->x;
    for (int n = size - 1; n > 0; n--) {
        (arr + n)->x = (arr + n - 1)->x;
    }
    arr->x = lastVal;
}

int main() {
    int size,n;
    int sum=0;
    cout<<"Creating dynamic array"<<endl<<"enter array size"<<endl;
    cin>>size;

    Points* a = createArray(size);

    for (int n=0;n<size;n++) {
        cout<<"Enter element "<<n<<": ";
        cin>>(a+n)->x;
    }
cout<<"array elements: ";
    printArray(a,size);

    cout<<"/nSum of array elements: "<<findSum(a,size)<<endl;
    cout<<endl<<"---------------"<<endl;

    cout<<"Shifting array to the right"<<endl;
    shiftRight(a,size);
    cout<<"array after shift right: ";
   printArray(a,size);


int val1=5,val2=6;
    cout<<"Swapping two numbers"<<endl<<"before swap"<<val1<<val2<<endl;
    swapValues(&val1,&val2);
    cout<<"array after swap"<<endl;
    cout<<val1<<" "<<val2<<endl;

    cout<<endl<<"deleting array..."<<endl;
deleteArray(a);
    return 0;
}



