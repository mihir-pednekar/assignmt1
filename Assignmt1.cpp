#include <iostream>
#include <cstdlib>

//returns a random number between range min and max
int getRandom(int min, int max){
    if(max<min){
        //if max is less than min then swap
        int temp=min;
        min=max;
        max=temp;
        //std::cout<<"Swap min: "<<min<<" max: "<<max<<"\n";
    }
    if(max==min){
        std::cout<<"Invalid min max range.\n";
        return -1;
    }
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
            std::cout<<"]";
        else
            std::cout<<",";
    }
}
int main(int argc, char *argv[]) {
	//std::cout<<"Random : "<<getRandom(5,5)<<"\n";
	int size=10, min=1, max=5;
	if(argc>=3){
    	int array[size]={0};
    	min = std::stoi(argv[1]);
    	max = std::stoi(argv[2]);
    	fillArray(array, size, min, max);
    	printArray(array, size);
	}
	else
	    std::cout<<"Incorrect number of arguments - please call with fileName min max";
	return 0;
}
