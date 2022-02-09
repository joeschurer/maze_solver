#include <iostream>
#include "image.h"
#include "deque.hpp"
#include <vector>


/* Joseph Schurer
 * Project 4
 * 7/12/2020 
 */
 
//defined location type to make position tracking friendlier
struct location{
	intmax_t row;
	intmax_t col;
};

//function header for the vector search function
bool vectorFind(std::vector<location> &x,location &s);

int main(int argc, char *argv[])
{
	//verify that the user provided the correct number of arguments
	if(argc != 3){
		std::cerr << "Error Invalid number of arguments provided!" << std::endl;
		return EXIT_FAILURE;
	}
  
	//attempt to read in the image
	try{
		//create image object for reading
		Image<Pixel> input = readFromFile(argv[1]);	
		
		//variables to hold info about image
		intmax_t height = input.height();
		intmax_t width = input.width();
		Pixel start = RED;
		Pixel maze = WHITE;
		Pixel wall = BLACK;
		intmax_t startRow=-1;
		intmax_t startCol;
		
		//read the image into a 2d array
		Pixel image_array[height][width];
		for(intmax_t j=0;j<width;j++){
			for(intmax_t i=0;i<height;i++){
				image_array[i][j] = input(i,j);
				
				//if the pixel is red it is the start save its positon
				if(input(i,j)==start){
					//verify that there is only one red pixel
					if(startRow != -1){
						std::cerr << "Error Image contains more than one start position!" << std::endl;
						return EXIT_FAILURE;
					}
					startRow = i;
					startCol = j;
				}
				//else check that the pixel is Black or white
				else{
					if((input(i,j)!=wall)&&(input(i,j)!=maze)){
						std::cerr << "Error Image contains a pixel that is not black, white, or red." << std::endl;
						return EXIT_FAILURE;
					}
				}
			}
		}//image is read into array and we have starting location
		
		//check that after reading in the image at least one red pixel is there
		if(startRow==-1){
			std::cerr << "Error Image does not contain red pixel!" << std::endl;
			return EXIT_FAILURE;
		}
		
		//bool to test if is solution has been found
		bool check = false;
		
		//test for start pixel being on edge
		if((startRow==0)||(startCol==0)||(startRow==height-1)||(startCol==width-1)){
			//make the pixel green as it is the soltuton
			Pixel sol = GREEN;
			image_array[startRow][startCol] = sol;
			std::cout<<"Solution Found" << std::endl;
			check = true;
		}
		//otherwise must find the solution
		else{
			//Vector of visited positions
			std::vector<location> visited;
			
			//initialize the double-ended queue
			Deque<location> frontier;
			
			//push the start node onto the frontier
			location start;
			start.row = startRow;
			start.col = startCol;
			frontier.pushBack(start);
			
			//mark the start as visited
			visited.push_back(start);
						
			//loop while the queue is not empty
			
			while(!frontier.isEmpty()){
				//remove the first item from the frontier and mark visited
				location s = frontier.back();
				frontier.popBack();
				//visited.push_back(s);
				
				/* get adjacent pixel
				 * Follow the given order of (r-1,c) (r+1,c)
				 * (r,c-1) and (r,c+1) 
				 */
				
				//this will indicate if an pos has been visited
				bool test[4];
				
				//check for (r-1,c) in the vector using a temporary location
				location temp[4];
				temp[0].row = s.row-1;
				temp[0].col = s.col;
				test[0]=vectorFind(visited,temp[0]);
				
				//test (r+1,c)
				temp[1].row = s.row+1;
				temp[1].col = s.col;
				test[1]=vectorFind(visited,temp[1]);
				
				//test (r+1,c)
				temp[2].row = s.row;
				temp[2].col = s.col-1;
				test[2]=vectorFind(visited,temp[2]);
				
				//test (r+1,c)
				temp[3].row = s.row;
				temp[3].col = s.col+1;
				test[3]=vectorFind(visited,temp[3]);
				
				//test white PIXEL
				Pixel testPixel = WHITE;
				
				
				//iterate through each possible adjacent position
				for(int i=0;i<4;i++){
					//ifthe location has not been vistied
					if(!test[i]){
						//check the pixel only if it is white
						if(image_array[temp[i].row][temp[i].col] == testPixel){
							
							//if the location is an exit
							if((temp[i].row==0)||(temp[i].col==0)||(temp[i].row==height-1)||(temp[i].col==width-1)){							
								//make the pixel green as it is the soltuton
								Pixel sol = GREEN;
								image_array[temp[i].row][temp[i].col] = sol;
								
								std::cout<<"Solution Found" << std::endl;
								check=true;
								
								//exit the loop as solution found
								while(!frontier.isEmpty()){
									frontier.popBack();
								}
								test[0]=false;
								test[1]=false;
								test[2]=false;
								test[3]=false;
								
								break;
							}
							
							else{//the locaiton was not an exit
								visited.push_back(temp[i]);
								frontier.pushFront(temp[i]);
							}
						}
					}
				}
			}
			
		}
		//if we checked every path and did not find a solution indicate that
		if(!check){
			std::cout<<"No Solution Found" << std::endl;
		}//after this the output image will match the original
		
		//setup the output image
		Image<Pixel> output(width,height);
		for(intmax_t j=0;j<width;j++){
			for(intmax_t i=0;i<height;i++){
				output(i,j)=image_array[i][j];
			}
		}
		
		//write the output image to the provided file
		writeToFile(output,argv[2]);
		
		
		
	}

	//catch any exception, print details to standard error, and exit
	catch(std::exception &e){
		std::cerr <<"Error "<< e.what() << std::endl;
		return EXIT_FAILURE;
	}
  
  
}

//function to indicate if an item is in an array
bool vectorFind(std::vector<location> &x,location &s){
	for(intmax_t i=0;i<x.size();i++){
		if((x[i].row == s.row)&&(x[i].col == s.col)){
			
			return true;
		}
	}
	
	return false;
}
