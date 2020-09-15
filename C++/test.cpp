#include "colormod.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>


std::vector<std::string> convertStringToWords(std::string &s){
	std::vector<std::string> v;
	std::string result = "";

	for(char ch : s){
		if(ch == ' '){
			if(result != "")
				v.push_back(result);
			result.clear();
		}
		else
			result.push_back(ch);
	}
	
	if(result != "")
		v.push_back(result);

	while(v.size() and v.back() == " ")
		v.pop_back();

	return v;
}
int main(){

	bool hasDifferenceInContent = false;
	bool hasDifferenceInOrder = false;

	std::ifstream file1("expectedOutput.txt"); 
	std::ifstream file2("output.txt");


	std::vector<std::string> currExpectedResult;
	std::vector<std::string> currActualResult;

	std::vector<std::vector<std::string>> expectedResult;
	std::vector<std::vector<std::string>> actualResult;

	if(file1.is_open()){
		std::string line;
		while(std::getline(file1,line)){
			currExpectedResult = convertStringToWords(line);
			expectedResult.push_back(currExpectedResult);
		}
		
	}


	if(file2.is_open()){
		std::string line;
		while(std::getline(file2,line)){
			currActualResult = convertStringToWords(line);
			actualResult.push_back(currActualResult);
		}
		
	}

	if(actualResult.size() != expectedResult.size())	hasDifferenceInOrder = true;
		
	else if(hasDifferenceInOrder == false){
		for(int i = 0 ; i < actualResult.size() ; i++){
			if(actualResult[i].size() == expectedResult[i].size())
				continue;
			else{
				hasDifferenceInOrder = true;
				break;
			}
		}
	}

	if(hasDifferenceInOrder){
		Fail();
		return 0;
	}

	else{
		/* Check for difference in content */

		for(int i = 0 ; i < (int) actualResult.size() ; i++){
			for(int j = 0 ; j < (int) actualResult[i].size() ; j++){
				if(actualResult[i][j] == expectedResult[i][j])
					continue;
				else{
					hasDifferenceInContent = true;
					break;
				}
			}
		}

	}

	
	if(hasDifferenceInContent){
		Fail();

		for(int i = 0 ; i < (int) expectedResult.size() ; i++){
			for(int j = 0 ; j < (int) expectedResult[i].size() ; j++){

				if(actualResult[i][j] == expectedResult[i][j])
					Matched(actualResult[i][j]);
				else
					Mismatched(expectedResult[i][j]);
			}
			std::cout<<std::endl;
		}
		

	}
	else
		Pass();
	return 0;
}
