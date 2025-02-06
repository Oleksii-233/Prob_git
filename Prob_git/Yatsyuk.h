#pragma once
#indef Yatsiyk


void readfromfile(ifstream& file, PeopleInformation inf){
  file.open("z1.dat");
  file1.clear();
	file1.seekg(0);
  cout <<setw(3)<<"№"<< setw(10)<<<<setw(10)<<"Ім'я"<<setw(8)<<"Стать"<<setw(5)<<"Ріст"<<setw(5)<<"Вага"<<setw(7)<<"№ одежі"<<setw(8)<<"№ взуття"<< endl;	
		int i=0;
  while (file.read((char*)&inf, sizeof inf))
    {
			  cout <<setw(3)<<i<< setw(10)<<<<setw(10)<<"Ім'я"<<setw(8)<<"Стать"<<setw(5)<<"Ріст"<<setw(5)<<"Вага"<<setw(7)<<"№ одежі"<<setw(8)<<"№ взуття"<< endl;	
		i++;
    }
		file1.close();
		file1.clear();

}
