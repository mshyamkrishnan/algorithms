#include <iostream>
#include <vector>
/*executable code available in https://is.gd/uF2rmx*/
using namespace std;
int returnMinIndex(const vector<int> &input);
int main() {
    cout<<"Hello";
    vector<int> inpu = {5,4};
    cout << "hi\n";
    cout << "min=" << returnMinIndex(inpu) << endl;
    return 0;
}

int returnMinIndex(const vector<int> &input){
    
    if(input.empty())
        return -1;
    if(input.size() == 1)
        return 0;
    if(input[0] < input[input.size()-1])
        return 0;
    cout << "cp1\n";
    int start = 0;
    int end = input.size()-1;
    int middle = start + (end-start)/2;
    while(start < end){
        cout << "cp2\n" ;
        cout << "start = " << input[start] << "end = " << input[end] << "mid = " << input[middle] <<endl;
        if(input[start] < input[end])
            return start;
        if(input[start] > input[middle]){
            end = middle;// - 1;
            middle = start + (end-start)/2;
        }
        else if(input[middle] > input[end]){
            start = middle + 1;
            middle = start + (end-start)/2;
        }
        cout << "-start = " << input[start] << "end = " << input[end] << "mid = " << input[middle] <<endl;
        
    }
    
    
}

