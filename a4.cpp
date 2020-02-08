//a4.cpp
/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : Chamodi Basnayake
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include "cmpt_error.h"
#include "Priority_queue.h"

using namespace std;


///////////////////////////////// HEAP SORT //////////////////////////////////////////////
class heapSort: public Priority_queue{
private:
	//creating a vector and a counter as private variables
	vector<int> v;
	unsigned long long int counter = 0;

public:

	heapSort(){
		v.resize(size(),0);
	}

	int size() const{
		return v.size();
	}

	bool empty() const{
		return v.empty();

	}

	//Inserting into the heap
	void insert(const int h){
		v.push_back(h);
	}

	//Save the min value, then erase that elemnt from the heap. Resort the vector
	int pop_min(){
		int result = v[0];
		v.erase(v.begin());
		sortHeap (size());
		return result;
	}

	//Sort the function starting from the middle and going towards index 0
	//Call the helper function, which does all the comparisons
	void sortHeap (int size){
		for (int i = size/2 -1; i >= 0; i--){
			sortHelper (size,i);
		}
	}

	//Helper function that do the comparisons
	void sortHelper (int size, int i){

		//Defining parent and left and right children
		int parent = i;
		int left = 2*i + 1;
		int right = 2*i + 2;
		
		//Check if a left child exists
		if (left < size){
			//Increment counter as a comparison is being made
			counter++;
			//Compare left child and parent. IF left is smaller, then replace index value of parent
			if (v[left] < v[parent]){
				parent = left;
			}
		}
		
		//Similar to that of the left child
		if (right < size){
			counter++;
			if (v[right] < v[parent]){
				parent = right;
			}
		}

		//Check if the if loops above were used; if any of the children were smaller than them.
		//A swap in values need to happen between parent and the child
		if (parent != i){
			swap(v[i], v[parent]);
			sortHelper(size, parent);
		}
	}

	//Return the counter
	unsigned long long int count(){
		return counter;
	}

};



/////////////////////////////////// SELECTION SORT //////////////////////////////////////////////
class selectSort: public Priority_queue{
private:
	//Private vector and counter
	vector<int> v;
	unsigned long long int counter = 0;

public:

	selectSort(){
		v.resize(size(),0);
	}

	int size() const{
		return v.size();
	}

	bool empty() const{
		return v.empty();

	}

	//Simply push back value for insertion
	void insert(const int h){
		v.push_back(h);
	}

	//Poping the minimum value and sorting through the vector to find it
	int pop_min(){

        int min = v[0];
        int index = 0;
        for (int i = 0; i < size(); i++) {
        	//counting as a comparison is made
            counter++;
            //check if the index is the new minimum. If it is, store the index number
            if (v[i] < min){
                min = v[i];
                index = i;
                
            }
        }

        //Use the index number to reshuffle the vector
        if (index == size() - 1){
            v.resize(size()-1);
        }else{
            for (int i = index; i < size() -1 ; i++){
                v[i] = v[i + 1];
            }

            v.resize(size() -1);
        }

        return min;  
    }

	unsigned long long int count(){
		return counter;
	}
};



/////////////////////////////////// INSERTION SORT //////////////////////////////////////////////
class insertionSort: public Priority_queue{
private:
	vector<int> v;
	unsigned long long int counter = 0;;

public:

	insertionSort(){
		v.resize(size(),0);
	}

	int size() const{
		return v.size();
	}

	bool empty() const{
		return v.empty();

	}

	void insert(const int h){

		// push the value back
        v.push_back(h);

        //Perform insertion sort
	    for(int i = 1; i < size(); ++i){
	        int j = i - 1;
	        int temp = v[i];

	      	while (j >= 0 && v[j] > temp){
	      		counter++;
		        v[j+1] = v[j];
		        j--;
	      	}

	      	v[j+1] = temp;
	    }
    }

    //poping the first element, and reshuffling the rest of the vector
	int pop_min(){

		int result = v[0];

		if(size() == 1){
			v.clear();
			return result;
		}

		for (int i = 0; i < size(); i++){
			v[i] = v[i+1];
		}

		v.resize(size()-1);

		return result;
	}

	unsigned long long int count(){
		return counter;
	}
};

//Sort function for selection sort
void selectionSort(vector<int>& vec) {

	cout << "START SELECTION" << endl;
    
    selectSort select;

    //Take all vector elements and input into a PQ
    for (int i = 0; i < vec.size(); i++){
    	select.insert(vec[i]);
    }

    //Out put all elements from PQ to vector
    for (int i = 0; i < vec.size(); i++){
    	vec[i] = select.pop_min();
    }

    cout << endl;
	cout << "counter " << select.count() << endl;
    
}

void insertSort(vector<int>& vec) {

	cout << "START Insertion" << endl;
    
    insertionSort insertion;

    //Take all vector elements and input into a PQ
    for (int i = 0; i < vec.size(); i++){
    	insertion.insert(vec[i]);
    }

    //Out put all elements from PQ to vector
    for (int i = 0; i < vec.size(); i++){
    	vec[i] = insertion.pop_min();
    }

    cout << endl;
	cout << "counter " << insertion.count() << endl;

}

void sortHeap(vector<int>& vec) {

	cout << "START Heap Sort" << endl;
    
    heapSort heap;

    //input all elements to a heap
    for (int i = 0; i < vec.size(); i++){
    	heap.insert(vec[i]);
    }

    //Sort the heap
    heap.sortHeap(heap.size());

    //Out put all elements from heap to vector
    for (int i = 0; i < vec.size(); i++){
    	vec[i] = heap.pop_min();
    }

   
	cout << endl;
	cout << "counter " << heap.count() << endl;

}

//Use of lambda function to count the comparisons : citations provided
unsigned long long int stlSort(vector<int>& v) {

	cout << "START STL sort" << endl;

	unsigned long long int num = 0;
    
    sort(v.begin(), v.end(), [&num](unsigned long long int l, unsigned long long int r) { 
        
        ++num;
        return l < r;
    	}
    );

    return num;
}

//Create random numbers to fill vector
vector<int> ranVec (int n) {

	vector<int> p (n);

	//Creat a vector of numbers
	for (int i = 0; i < n + 1; i++){
		p[i] = i;
	}
	
	vector<int> a (n);

	//Use randomized ways to get unique numbers into a vector: Citation provided
	for (int i = n; i>0; --i){

		int j = rand()%i;
		int temp = p[i];
		p[i] = p[j];
		p[j] = temp;
	}

	for (int i=0; i < a.size(); ++i){
	    a[i] = p[i];
	}

	return a;
}

int main(){

	int num = 5000;
	vector<int> p (num);

	for (int i = 0 ; i < 21; i++){
		p = ranVec(num);

		//!! Insertion sort comparisons may come out as 0, when all sorts are implemented at the same time
		//If done alone, insertionSort does not give 0 as the number of comparisons
		//There is a fault in the coding, but it is able to calculate some number of comparisons
		
		insertSort(p);
		selectionSort(p);
		sortHeap(p);
		unsigned long long int count = stlSort(p);
		cout << count << endl;
		
		num = num * 2;
	}	
	
}


/*
/////////////////////////////////////////CITATION///////////////////////////////

- Heap sort: used the following references, specially for the sortHelper function
	https://www.youtube.com/watch?v=oAYtNV6vy-k&t=221s					
	https://www.geeksforgeeks.org/heap-sort/				

- Selection sort: Used the following to get a better idea of the problem
	https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/tutorial/		
	https://www.geeksforgeeks.org/selection-sort/				

- Insertion sort: Use these as primary sources to understand how the algorithm works
	https://www.thecrazyprogrammer.com/2014/12/insertion-sort.html						

-STL Lambda function: Got it straight from the website:
	https://www.dreamincode.net/forums/topic/322634-lambda-functions-and-stdsort/

-ranVec function: Got the idea to implement it from this website
	http://www.cplusplus.com/forum/beginner/91557/

*/
