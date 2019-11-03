#include <iostream>
#include <cstdlib>

//returns a random number between range min and max
int getRandom(int min, int max){
    int random = rand()%max + min;
    while(true){
        //std::cout<<"Test Random: "<<random<<"\n";
        if(random>=min && random<=max)
            break;
        else
            random = rand()%max + min;
    }
    return random;
}

//fills array of parameter size with random numbers using getRandom() function
void fillArray(int data[], int size, int min, int max){
	for(int i=0;i<size;i++){
		data[i]=getRandom(min,max);
    	}
}

//prints array of parameter size
void printArray(int data[], int size){
    std::cout<<"[";
    for(int i=0;i<size;i++){
        std::cout<<data[i];
        if(i==size-1)
            std::cout<<"]\n";
        else
            std::cout<<",";
    }
}

// swap by reference.
void swap(int &min, int &max){
	//if max is less than min then swap
        int temp=min;
        min=max;
        max=temp;
	//std::cout<<"Swapping as max is less than min.\n";
     	//std::cout<<"Swap min: "<<min<<" max: "<<max<<"\n";
}

//main() function with command line arguments.
int main(int argc, char *argv[]) {
	//std::cout<<"Random : "<<getRandom(5,5)<<"\n";
	int size=10, min=0, max=0;
	if(argc>=3){
    		int array[size]={0};
    		min = std::stoi(argv[1]);
    		max = std::stoi(argv[2]);
    			if(max!=min){
				if(max<min){
					//swap by reference.
					swap(min,max);
				}
				fillArray(array, size, min, max);
    				printArray(array, size);
			}
			else{
				std::cout<<"Invalid range as max==min.\n";
			}
	}
	else
	    std::cout<<"Incorrect number of arguments - please call with fileName min max.\n";
	return 0;
}
