#include "SingleLinked.cpp"
#include <fstream>


void xuatfile(LIST l) {
	
	NODE *p;	
	p = l.first;
   ofstream outfile; 
   outfile.open("qtm.dat"); 


	while (p!= NULL) { 
      
     p = p->link;
	}

   
}