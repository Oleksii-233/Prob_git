#pragma once
#indef Yatsiyk


void readfromfile(ifstream& file){
 PeopleInformation inf[50];
	int inf=0;
File.open("PeopleInformation.dat", ios::in, ios::binary);
  file1.clear();
	file1.seekg(0);
  cout <<setw(3)<<"№"<< setw(10)<<<<setw(10)<<"Ім'я"<<setw(8)<<"Стать"<<setw(5)<<"Ріст"<<setw(5)<<"Вага"<<setw(7)<<"№ одежі"<<setw(8)<<"№ взуття"<< endl;	
	
  while (file.read((char*)&inf, sizeof inf))
    {
	cout <<setw(3)<<inf.Number<< setw(10)<<inf.Surname<<setw(10)<<inf.Name<<setw(8)<<inf.Sex<<setw(5)<<inf.Height<<setw(5)<<inf.Weight<<setw(7)<<inf.ClothesNumber<<setw(8)<<inf.ShoesNumber<< endl;	
		
    }
		file1.close();
		file1.clear();

}
