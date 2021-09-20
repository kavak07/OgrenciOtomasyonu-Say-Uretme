#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


//PROGRAM 1
struct ogrenciler{
        string No;
        string Ad;
        string Soyad;
        string Mail;
        string Telefon;
        string DogumTarihi;
        float Vize;
        float Odev;
        float Final;
};

struct veribasligi{
	
        string No;
        string Ad;
        string Soyad;
        string Mail;
        string Telefon;
        string DogumTarihi;
        string Vize;
        string Odev;
        string Final;
};

int idSayac;
int N ;
ogrenciler* s[200];
veribasligi* vb=new veribasligi;
ifstream input; 
fstream output;  
string next;
int secim;	
    	   
void GetirOgrenci(){
    

     	
       input.open("Ogrenciler.dat"); 
        if(input.is_open()==false){
        	cout<<"Ogrenciler.dat dosyas� bulunamad�.";
        	exit(0);
		}
        input>>next;
        input>>next;
        input>>next;
        input>>next;
        input>>next;
        input>>next;
        input>>next;
        input>>next;

        
        input >> vb->No >> vb->Ad >> vb->Soyad >> vb->Mail >> vb->Telefon >>vb->DogumTarihi >> vb->Vize >> vb->Odev >> vb->Final;

        for(int i=0; i< N; i++){
                s[i] = new ogrenciler; 
                input >> s[i]->No >> s[i]->Ad >> s[i]->Soyad >> s[i]->Mail >> s[i]->Telefon >> s[i]->DogumTarihi >> s[i]->Vize >> s[i]->Odev >> s[i]->Final;
        }
        input.close();
        
}

void veribasligi(){
	
	
	  cout << vb->No <<" "<< vb->Ad <<" "<< vb->Soyad<<" " << vb->Mail <<" "<<vb->Telefon <<" "<<vb->DogumTarihi <<" "<< vb->Vize <<" "<< vb->Odev <<" "<< vb->Final<<endl; 
}

void ogrenciListele(){
	

    cout << "\n--------T�m Bilgiler Listesi------------"<<endl;
    
    veribasligi();
	
	for(int i=0; i< N; i++){
                
	    
	    cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final << endl;
		
		}
	
}

void GNOHesapla(){
	
	cout << "\n\n----------------GNO Bilgileri Listesi---------------" <<endl;
        
        output.open("Kalanlar.txt",ios::out);
        output.close();
        output.open("Ge�enler.txt",ios::out);
        output.close();
         for(int i=0; i< N; i++){
		      
              float gno= (0.3*s[i]->Vize + 0.2*s[i]->Odev + 0.5*s[i]->Final);
                
				if(gno<=46){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"FF" << " GNO :"<< gno <<" KALDI"<< endl;
					output.open("Kalanlar.txt",ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"FF" << " GNO :"<< gno <<" KALDI"<<"\n";
					output.close();
				}
				else if(gno>46&&gno<=49)
				{
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"CD " << " GNO :"<< gno <<" GE�T�"<<endl;
					output.open("Ge�enler.Txt", ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"CD " << "GNO :"<< gno <<" GE�T�"<<"\n";
					output.close();
				}	
				else if(gno>=50&&gno<=55)
				{
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"CC " << " GNO :"<< gno <<" GE�T�"<<endl;
					output.open("Ge�enler.Txt", ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<<"CC "  << "GNO :"<< gno <<" GE�T�"<<"\n";
					output.close();
				}
						else if(gno>=56&&gno<=60)
				{
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"CB " << " GNO :"<< gno <<" GE�T�"<<endl;
					output.open("Ge�enler.Txt", ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"CB " << "GNO :"<< gno <<" GE�T�"<<"\n";
					output.close();
				}
					else if(gno>=61&&gno<=65)
				{
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"BC " << " GNO :"<< gno <<" GE�T�"<<endl;
					output.open("Ge�enler.Txt", ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<<"BC "  << "GNO :"<< gno <<" GE�T�"<<"\n";
					output.close();
				}
						else if(gno>=66&&gno<=70)
				{
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"BB" << " GNO :"<< gno <<" GE�T�"<<endl;
					output.open("Ge�enler.Txt", ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"BB" << "GNO :"<< gno <<" GE�T�"<<"\n";
					output.close();
				}
					else if(gno>=77&gno<=83)
				{
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"AB" << " GNO :"<< gno <<" GE�T�"<<endl;
					output.open("Ge�enler.Txt", ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"AB" << "GNO :"<< gno <<" GE�T�"<<"\n";
					output.close();
				}
				else if(gno>=84&gno<=100)
				{
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"AA" << " GNO :"<< gno <<" GE�T�"<<endl;
					output.open("Ge�enler.Txt", ios::app);
					output<< s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final <<"AA" << "GNO :"<< gno <<" GE�T�"<<"\n";
					output.close();
				}
				
        }
}
        		
void GNOKalan(){
	
		cout << "\n\n----------------Kalanlar Listesi---------------" <<endl;
        
         for(int i=0; i< N; i++){             
                 
              float gno= (0.3*s[i]->Vize + 0.2*s[i]->Odev + 0.5*s[i]->Final);
                
				if(gno<=46){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " FF " << " GNO :"<< gno <<" KALDI"<< endl;		
				}
				else if(gno>46&&gno<=49){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " CD " << " GNO :"<< gno <<" GE�T�"<< endl;		
				}
				else if(gno>=50&&gno<=55){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " CC "<< " GNO :"<< gno <<" GE�T�"<< endl;		
				}
				else if(gno>=56&&gno<=60){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " CB " << " GNO :"<< gno <<" GE�T�"<< endl;		
				}
					else if(gno>=61&&gno<=65){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " BC " << " GNO :"<< gno <<" GE�T�"<< endl;		
				}
					else if(gno>=66&&gno<=70){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< "  BB " << " GNO :"<< gno <<" GE�T�"<< endl;		
				}
					else if(gno>=71&&gno<=76){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " BA " << " GNO :"<< gno <<" GE�T�"<< endl;		
				}
					else if(gno>=77&gno<=83){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " AB " << " GNO :"<< gno <<" GE�T�"<< endl;		
				}
					else if(gno>=84&gno<=100){
					cout << s[i]->No <<" "<< s[i]->Ad <<  " " << s[i]->Soyad <<  " " << s[i]->Mail<<  " " << s[i]->Telefon<<  " " << s[i]->DogumTarihi <<  " " << " "<< s[i]->Vize << " "<< s[i]->Odev<<" "<< s[i]->Final<< " AA " << " GNO :"<< gno <<" GE�T�"<< endl;		
				}
				  	}
	
}
		
void veriEkle(){
	
	cout << " \n\n------------ Kay�t Ekleme ----------"<<endl;
	string data,out;
	cout << "Ad :";
    cin>>data;
    out=out+data+" ";
    cout << "Soyad :";
    cin>>data;
    out=out+data+" ";
    cout << "Mail :";
    cin>>data;
    out=out+data+" ";
    cout << "Telefon :";
    cin>>data;
    out=out+data+" ";
    cout << "Do�um Tarihi :";
    cin>>data;
    out=out+data+" ";
    cout << "Vize :";
    cin>>data;
    out=out+data+" ";
    cout << "�dev :";
    cin>>data;
    out=out+data+" ";
    cout << "Final :";
    cin>>data;
    out=out+data;
    idSayac++;
    cout<<"Eklenen Veri : "<<idSayac<<" "<<out;
    output.open("Ogrenciler.dat" , ios::app);
	output<< "\n"<< idSayac <<" "<<out;
	output.close();
	output.open("counter.cr",ios::out);
    output<<idSayac;
    output.close();	
    N=idSayac;
}
		
void program1(){
	
	
        input.open("count.sy"); 
        if(input.is_open()){
     	
     	input>>idSayac;
     	N=idSayac;
     	input.close();
        }
     	else{
     		output.open("count.sy",ios::out);
     		output<<100;
     		output.close();
     		idSayac=100;
     		N=100;
     		
     	  }
		 
	GetirOgrenci();
	 cout << " \n\n------------ ��RENC� OTOMASYONU ��LEM MEN�S� ----------"<<endl;
      		cout << "T�m Bilgileri Listele - 1"<<endl;
      		cout << "Notlar� Sonu�land�r   - 2"<<endl;
      		cout << "Kalanlar� G�r         - 3"<<endl;
      		cout << "Kay�t Ekle            - 4"<<endl;
      		cout << "Se�iniz (1 - 2 - 3 - 4) : ";
      	    cin>>secim;
      	    
			  if(secim==1)
			  	  ogrenciListele();
		      else if(secim==2)
      	        GNOHesapla();
      	      else if(secim==3)
      	        GNOKalan();
      	      else if(secim==4)
      	       veriEkle();
      	        
		  
		 cout << "\nProgram Men�s�ne Geri D�n - 1 / ��k�� - 2 :";
      	    cin>>secim;
      		
			  if(secim==1)	
      			program1();
      		  
	
}

//PROGRAM 1
//PROGRAM 2

int Rastgele(int max,int min , int adet){
	
	srand(time(0));
	float toplam=0,sayi;
	int sayilar[adet];
	
	for(int i = 0;i<adet;i++){	
	sayi= rand() % (max - min + 1) + min;
	sayilar[i]=sayi;
	toplam=sayi+toplam;
	cout<<sayi<<endl;
}
	float ortalama = toplam/adet;
	
	cout<<"�retilen "<<adet << " adet say�n�n ortalamas� "<<ortalama<<endl;
	
	cout<<"Dosyaya Kay�t Edilsin mi ? E/H ";
    char yanit;
	cin>>yanit;
	if(yanit=='E' || yanit=='e'){
		output.open("Rastgele.txt",ios::out);
		for(int i = 0;i<adet;i++){
     	output<<"Say� "<<i<<" :"<<sayilar[i]<<"\n";
     	
		 }
		 output<<"Ortalamas� "<<ortalama;
		 output.close();
		
	}
	}
	
	
	


void sayiUretme(){
	
	int min , max,adet ;
	cout << " \n\n **Rastgele Say� �retme**"<<endl;	
	
     cout<<"Minimum De�er Giriniz : ";
     cin>>min;
      cout<<"Maksimum De�er Giriniz : ";
     cin>>max;
      cout<<"Adet Giriniz : ";
     cin>>adet;
     Rastgele(max,min,adet);
      
     
   	
}

void cikis(){
	
	cout << " \n\n------------ ��k�� ----------"<<endl;	

}


void kod2(){
	
	
	  cout<< " \n\n****Rastgele Say�****"<<endl;
      	
		  
      		  
	
}

int main(void){
      
      setlocale(LC_ALL,"Turkish");
    
 
      	cout << "Hangi programa giri� yapmak istiyorsunuz ?"<<endl;
      	cout << "��renci Not ��lemleri / 1 - Rastgele Hesapmalama / 2 "<<endl;
      	cout << " Bir Se�im Yap�n : ";
      	cin>>secim;
      	
      	if(secim==1){
			program1();
				}		
		 else if (secim==2){
		kod2();	
		sayiUretme();
			
			 }
		


return 0;
}  
