#include<fstream>

void extend(){

	
	system("gedit input.txt");
	system("gedit expectedOutput.txt");
	system("touch output.txt");


	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

}
