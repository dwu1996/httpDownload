#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <windows.h>
#include <time.h>
using namespace std;
#define BUF_SIZE 16384

int main()
{
	string powershellscript_path = "C:\\xampp\\htdocs\\toDownload.ps1";
	while(1)
	{
		string tmp, tmp2;
		string data, data2;
		//data = 12345617, data2 = 12345619
		
		cout<<"Getting Data..."<<endl;
		system("start powershell.exe C:\\xampp\\htdocs\\toDownload.ps1");
		fstream data_page, data_page2;
		int counter = 0, counter2 = 0;
		
		data_page.open("sample.htm",ios::in);
		while(data_page>>tmp){data+=tmp;}
		data_page.close();
		
		data_page2.open("sample2.htm",ios::in);
		while(data_page2>>tmp2){data2+=tmp2;}
		data_page2.close();
		
		cout<<"Getting Data END"<<endl;
		
		cout<<"Analyzing Data..."<<endl;
		int data_counter = 0, data_counter2 = 0;
		string ID[BUF_SIZE], MAC_ADDR[BUF_SIZE], MODE[BUF_SIZE], LONGITUDE[BUF_SIZE], LATITUDE[BUF_SIZE], CREATE_TIME[BUF_SIZE], UPDATE_TIME[BUF_SIZE];  //Using APIS
		string ID2[BUF_SIZE], MAC_ADDR2[BUF_SIZE], MODE2[BUF_SIZE], LONGITUDE2[BUF_SIZE], LATITUDE2[BUF_SIZE], CREATE_TIME2[BUF_SIZE], UPDATE_TIME2[BUF_SIZE];
		int pointer = 0;
		
		//deal with data1
		while(1)
		{
			if(data[pointer]==']'){break;}
			if(data[pointer-4]==34&&data[pointer-3]=='i'&&data[pointer-2]=='d'&&data[pointer-1]==34&&data[pointer]==':')
			{
				pointer++;
				while(data[pointer]!=',')
				{
					ID[data_counter]+=data[pointer];
					pointer++;
				}
			}
			else if(data[pointer-4]=='d'&&data[pointer-3]=='d'&&data[pointer-2]=='r'&&data[pointer-1]==34&&data[pointer]==':')
			{
				pointer++;
				while(data[pointer]!=',')
				{
					MAC_ADDR[data_counter]+=data[pointer];
					pointer++;
				}
			}
			else if(data[pointer-4]=='a'&&data[pointer-3]=='t'&&data[pointer-2]=='a'&&data[pointer-1]==34&&data[pointer]==':')
			{
				pointer++;
				while(data[pointer]!=',')
				{
					MODE[data_counter]+=data[pointer];
					pointer++;
				}
			}
			else if(data[pointer-4]=='l'&&data[pointer-3]=='a'&&data[pointer-2]=='t'&&data[pointer-1]==34&&data[pointer]==':')
			{
				pointer++;
				while(data[pointer]!=',')
				{
					LATITUDE[data_counter]+=data[pointer];
					pointer++;
				}
			}
			else if(data[pointer-4]=='l'&&data[pointer-3]=='n'&&data[pointer-2]=='g'&&data[pointer-1]==34&&data[pointer]==':')
			{
				pointer++;
				while(data[pointer]!=',')
				{
					LONGITUDE[data_counter]+=data[pointer];
					pointer++;
				}
			}
			else if(data[pointer-11]=='c'&&data[pointer-4]=='_'&&data[pointer-3]=='a'&&data[pointer-2]=='t'&&data[pointer-1]==34&&data[pointer]==':')
			{
				pointer++;
				while(data[pointer]!=',')
				{
					CREATE_TIME[data_counter]+=data[pointer];
					pointer++;
				}
			}
			else if(data[pointer-11]=='u'&&data[pointer-4]=='_'&&data[pointer-3]=='a'&&data[pointer-2]=='t'&&data[pointer-1]==34&&data[pointer]==':')
			{
				pointer++;
				while(data[pointer]!='}')
				{
					UPDATE_TIME[data_counter]+=data[pointer];
					pointer++;
				}
				data_counter++;
			}
			else
			{
				pointer++;
			}
		}
		//deal with data2
		pointer = 0;
		while(1)
		{
			if(data2[pointer]==']'){break;}
			if(data2[pointer-4]==34&&data2[pointer-3]=='i'&&data2[pointer-2]=='d'&&data2[pointer-1]==34&&data2[pointer]==':')
			{
				pointer++;
				while(data2[pointer]!=',')
				{
					ID2[data_counter2]+=data2[pointer];
					pointer++;
				}
			}
			else if(data2[pointer-4]=='d'&&data2[pointer-3]=='d'&&data2[pointer-2]=='r'&&data2[pointer-1]==34&&data2[pointer]==':')
			{
				pointer++;
				while(data2[pointer]!=',')
				{
					MAC_ADDR2[data_counter2]+=data2[pointer];
					pointer++;
				}
			}
			else if(data2[pointer-4]=='a'&&data2[pointer-3]=='t'&&data2[pointer-2]=='a'&&data2[pointer-1]==34&&data2[pointer]==':')
			{
				pointer++;
				while(data2[pointer]!=',')
				{
					MODE2[data_counter2]+=data2[pointer];
					pointer++;
				}
			}
			else if(data2[pointer-4]=='l'&&data2[pointer-3]=='a'&&data2[pointer-2]=='t'&&data2[pointer-1]==34&&data2[pointer]==':')
			{
				pointer++;
				while(data2[pointer]!=',')
				{
					LATITUDE2[data_counter2]+=data2[pointer];
					pointer++;
				}
			}
			else if(data2[pointer-4]=='l'&&data2[pointer-3]=='n'&&data2[pointer-2]=='g'&&data2[pointer-1]==34&&data2[pointer]==':')
			{
				pointer++;
				while(data2[pointer]!=',')
				{
					LONGITUDE2[data_counter2]+=data2[pointer];
					pointer++;
				}
			}
			else if(data2[pointer-11]=='c'&&data2[pointer-4]=='_'&&data2[pointer-3]=='a'&&data2[pointer-2]=='t'&&data2[pointer-1]==34&&data2[pointer]==':')
			{
				pointer++;
				while(data2[pointer]!=',')
				{
					CREATE_TIME2[data_counter2]+=data2[pointer];
					pointer++;
				}
			}
			else if(data2[pointer-11]=='u'&&data2[pointer-4]=='_'&&data2[pointer-3]=='a'&&data2[pointer-2]=='t'&&data2[pointer-1]==34&&data2[pointer]==':')
			{
				pointer++;
				while(data2[pointer]!='}')
				{
					UPDATE_TIME2[data_counter2]+=data2[pointer];
					pointer++;
				}
				data_counter2++;
			}
			else
			{
				pointer++;
			}
		}
		cout<<"Analyzing Data END"<<endl;
		data_counter--; data_counter2--;
		
		cout<<ID[data_counter]<<"  "<<MAC_ADDR[data_counter]<<"  "<<CREATE_TIME[data_counter]<<endl;
		cout<<ID2[data_counter2]<<"  "<<MAC_ADDR2[data_counter2]<<"  "<<CREATE_TIME2[data_counter2]<<endl;
		//system("pause");
		
		cout<<"Genarating Pages..."<<endl;
		string nl = "<br>";
		fstream user_page;
		fstream user_page2;
		user_page.open("I2N.html",ios::out | ios::trunc);
		user_page2.open("I2N_02.html",ios::out | ios::trunc);
		
		SYSTEMTIME st = {0};  //SYSTEM TIMER
		GetLocalTime(&st);
		user_page<<"System Time: "<<st.wYear<<"/"<<st.wMonth<<"/"<<st.wDay<<" "<<st.wHour<<":"<<st.wMinute<<":"<<st.wSecond<<nl<<nl;
		user_page2<<"System Time: "<<st.wYear<<"/"<<st.wMonth<<"/"<<st.wDay<<" "<<st.wHour<<":"<<st.wMinute<<":"<<st.wSecond<<nl<<nl;
		
		//GOOGLE MAP PRINTING
		/*string map = "<iframe width='100%' height='200' frameborder='0' scrolling='no' marginheight='0' marginwidth='0' src='https://maps.google.com.tw/maps?f=q&hl=zh-TW&geocode=&q=台北市新生南路三段90號&z=16&output=embed&t='></iframe>";
		user_page<<map<<nl<<nl;
		string map2 = "<iframe src=\"https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d3623.013397419356!2d120.95779551500083!3d24.760729784101045!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x34684a41bfbae837%3A0xed37af3f16a85b16!2z6I2J5qC55bua5oi_6aSQ5buz!5e0!3m2!1szh-TW!2stw!4v1547816641785\" width=\"600\" height=\"450\" frameborder=\"0\" style=\"border:0\" allowfullscreen></iframe>"; 
		user_page<<map2<<nl<<nl;
		string lat, lng;
		for(int i=0;i<7;i++)
		{
			if(LATITUDE[data_counter][i]=='.')
			{
				if(i==2){lat+=LATITUDE[data_counter][0];lat+=LATITUDE[data_counter][1];}
				if(i==3){lat+=LATITUDE[data_counter][0];lat+=LATITUDE[data_counter][1];lat+=LATITUDE[data_counter][2];}
				lat+="°";
				lat+=LATITUDE[data_counter][i+1];lat+=LATITUDE[data_counter][i+2];
				lat+=39;
				lat+=LATITUDE[data_counter][i+3];lat+=LATITUDE[data_counter][i+4];
				lat+=34; lat+='N';
			}
			if(LONGITUDE[data_counter][i]=='.')
			{
				if(i==2){lng+=LONGITUDE[data_counter][0];lng+=LONGITUDE[data_counter][1];}
				if(i==3){lng+=LONGITUDE[data_counter][0];lng+=LONGITUDE[data_counter][1];lng+=LONGITUDE[data_counter][2];}
				lng+="°";
				lng+=LONGITUDE[data_counter][i+1];lng+=LONGITUDE[data_counter][i+2];
				lng+=39;
				lng+=LONGITUDE[data_counter][i+3];lng+=LONGITUDE[data_counter][i+4];
				lng+=34; lng+='E';
			}
		}
		string maplink = "<a href=\"";
		maplink += "https://www.google.com/maps/place/"; maplink += lat; maplink += "+"; maplink += lng; maplink += "\">在GOOGLE MAP上尋找位置</a>";
		cout<<maplink<<endl;
		user_page<<maplink<<nl<<nl;*/
		
		for(int i=0;i<5;i++)  //PRINT DATA
		{
			user_page<<"Number "<<data_counter-i<<"'s data:"<<nl;
			user_page<<"ID: "<<ID[data_counter-i]<<nl<<"MAC ADDRESS: "<<MAC_ADDR[data_counter-i]<<nl;
			if(MODE[data_counter-i][0]==34&&MODE[data_counter-i][1]==34)
			{
				user_page<<"MODE: Sampled."<<nl;
			}
			else
			{
				user_page<<"MODE: Sampling GPS..."<<nl;
			}
			user_page<<"LATITUDE: "<<LATITUDE[data_counter-i]<<nl<<"LONGITUDE: "<<LONGITUDE[data_counter-i]<<nl<<"CREATE TIME: "<<CREATE_TIME[data_counter-i]<<nl<<"UPDATE TIME: "<<UPDATE_TIME[data_counter-i]<<nl<<nl;
		}
		for(int i=0;i<5;i++)  //PRINT DATA
		{
			user_page2<<"Number "<<data_counter2-i<<"'s data:"<<nl;
			user_page2<<"ID: "<<ID2[data_counter2-i]<<nl<<"MAC ADDRESS: "<<MAC_ADDR2[data_counter2-i]<<nl;
			if(MODE2[data_counter2-i][0]==34&&MODE2[data_counter2-i][1]==34)
			{
				user_page2<<"MODE: Sampled."<<nl;
			}
			else
			{
				user_page2<<"MODE: Sampling GPS..."<<nl;
			}
			user_page2<<"LATITUDE: "<<LATITUDE2[data_counter2-i]<<nl<<"LONGITUDE: "<<LONGITUDE2[data_counter2-i]<<nl<<"CREATE TIME: "<<CREATE_TIME2[data_counter2-i]<<nl<<"UPDATE TIME: "<<UPDATE_TIME2[data_counter2-i]<<nl<<nl;
		}
		user_page.close();
		user_page2.close();
		cout<<"Genarating Pages END"<<endl;
		
		cout<<"Success!"<<endl<<endl;
		Sleep(10000);
	}
}

