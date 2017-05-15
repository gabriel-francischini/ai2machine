#ifndef GENE_AI
#define GENE_AI

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <random>

using namespace std;

// This numbers are percentage, i.e.
// a 5 would mean that 5 of 100 suffers that
#define MUTATION_CHANCE 2
#define CROSSOVER_RATE 80

namespace rndGene{
mt19937 mt(1792 + time(NULL));
uniform_int_distribution<int> dist2(0,1);
uniform_int_distribution<int> dist100(0,100);
uniform_int_distribution<int> distchar(0,(int)(pow(2,sizeof(char)*8)-1));
}

//int counter = 0;

// gene  is a class that implements
// genetic logic, almost like a DNA
class gene{
    int _memory_limit;
    
    public:
        char *memory; 

    
        void checkMutations();
        void reproduce(gene *father, gene *mother);

        char *getMemory();
        // This function is read-only about it's data
        int memory_limit() const {return this->_memory_limit;}
        
        // At time construction, we
        // generate a random genome
        gene() : gene(rndGene::distchar(rndGene::mt)) {}

        gene(int memory_space){
            this->_memory_limit = memory_space-1;
            //counter += 1;
            //cout << counter << ". Allocating gene with " << this->_memory_limit+1 << " chars.\n";
            this->memory = new char[this->_memory_limit+1];

            for(int i=0; i<= this->_memory_limit;i++)
                this->memory[i] = rndGene::distchar(rndGene::mt);
            
        }

        gene(gene &copied){
            this->_memory_limit = copied.memory_limit();
            
            //counter += 1;
            //cout << counter << ". Allocating gene copy with " << this->_memory_limit+1 << " chars.\n";
            this->memory = new char[this->_memory_limit+1];

            for(int i=0; i<= this->_memory_limit;i++)
                this->memory[i] = copied.memory[i];
                
        }

        gene& operator=(const gene& assigned){
            // Don't self-assign! http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html
            if (this != &assigned){

                // Resize this.memory to match assigned's memory
                //cout << counter << ". Deallocating gene assigment with " << this->_memory_limit+1 << " chars.\n";
                delete[] this->memory;
                this->_memory_limit = assigned.memory_limit();
                //cout << counter << ". Allocating gene assigment with " << this->_memory_limit+1 << " chars.\n";
                this->memory = new char[this->_memory_limit+1];

                // Copy assigned's memory
                for(int i=0; i<= this->_memory_limit;i++)
                    this->memory[i] = assigned.memory[i];
            }

            return *this;
        }

        ~gene(){
            //counter -= 1;
            //cout << counter << ". Deallocating gene with " << this->_memory_limit+1 << " chars.\n";
            delete[] this->memory;
        }

};

char* gene::getMemory(){
    return &this->memory[0];
}

void gene::checkMutations(){
    for(int i=0; i <= this->_memory_limit; i++){
        if((rndGene::dist100(rndGene::mt)) <= MUTATION_CHANCE)
            this->memory[i] = rndGene::distchar(rndGene::mt);
    }
}


void gene::reproduce(gene *father, gene *mother){
    if((rndGene::dist100(rndGene::mt)) <= CROSSOVER_RATE){

        uniform_int_distribution<int> distplace(0, this->_memory_limit);
        
        int crossover_place = distplace(rndGene::mt);
        
        gene *copy=father;
        
        for(int i=0;i <= this->_memory_limit; i++){
            if(i==crossover_place)
                copy=mother;
            this->memory[i]=*(copy->getMemory()+i);
        }
        
    }
    else {
        gene *copy;
        if((rndGene::dist2(rndGene::mt))==0)
            copy = father;
        else
            copy = mother;
        
        for(int i=0; i <= this->_memory_limit;i++)
            this->memory[i]= copy->memory[i];
    }

    this->checkMutations();
}

#endif
