
/*

[2019-06-08] 
Hotel.h �ù� �Ƶ��� ͷ�ļ�
ʹ�÷�������Hotel.h����������е�ͷ�ļ�����
		��cppԴ�ļ��ϼ��� #include<Hotel.h> ���� 

*/
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <ctime>
#include <iostream>
#include <windows.h>

using namespace std;
#undef Scenic
#undef Position
#undef Region

#undef GuestRoom

class GuestRoom{//�ͷ��� 
	public:
		string name;//��������
		int capacity;//�������� ��ס������ 
		int price;//�۸� 
};
 
class GuestRoomClass: public GuestRoom{// GuestRoomClass�Ǽ̳�GuestRoom ������������Ľڵ��� 
	public:
		GuestRoomClass *next;
		GuestRoomClass(){
			cin>>name>>capacity>>price;
			next = NULL; 
		} 
		
		void printInfo(){
			cout<<name<<' '<<capacity<<' '<<price<<endl;
		}
};

class Hotel{//�Ƶ����� 
	public:
		string name;//�Ƶ��� 
		string address;//��ַ
		GuestRoomClass *RoomList;//��������ͷ 
		GuestRoomClass *RoomListTail;//��������β 
}; 

class HotelClass:public Hotel{//HotelClass �Ǽ̳�Hotel ������������Ľڵ��� 
	public:
		HotelClass *next; 
		
		/*
		
		���һ������ ,ע�����������ĳһ���Ƶ����
		���ǵ� name ���������� �������ԣ��󴲷� ��׼��֮�ࣩ ����û�в���
		������������ָ�� 
		
		*/
		GuestRoomClass* addRoom(){
			GuestRoomClass *tempPoint = new GuestRoomClass();
			if(this->RoomList==NULL) this->RoomList = tempPoint;
			else RoomListTail -> next = tempPoint;
			RoomListTail = tempPoint;
			return tempPoint; 
		}
		
		/*
		
		ɾ��һ�����䣬ע�����������ĳһ���Ƶ����
		�ӿ���һ��������ָ�� ��������ȷɾ�� 
		����һ��bool ��ʾ�Ƿ�ɹ�ɾ�� 
		
		*/
		bool deleteRoom(GuestRoomClass *Input){
			GuestRoomClass *Index = RoomList;
			GuestRoomClass *INext = Index->next;
			if(RoomList == Input){
				RoomList = RoomList->next;
				if(RoomListTail == Input) RoomListTail = NULL;
				free(Input);
				return true;
			}
			while(Index != NULL){
				if(INext == Input){
					Index->next = INext->next;
					if(INext == RoomListTail) RoomListTail = Index; 
					free(INext);
					return true; 
				}
				else{
					Index = Index-> next;
					if(INext != NULL) INext =INext->next;
				}
			}
			return false;
		} 
		
		HotelClass(){
			cin>>name>>address; 
			RoomList=RoomListTail = NULL;
			next = NULL; 
		}
		void printInfo(){
			cout<<name<<"  @"<<address<<endl; 
		}
};

class City{//ע�������Scenic.h��Region���ǲ�ͬ�� ��City���� 
	public:
		string name;//������
		HotelClass *HotelList;//�Ƶ�����ͷ
		HotelClass *HotelListTail;//�Ƶ�����β 
}; 

class CityClass:public City{//City Class �Ǽ̳�City ������������Ľڵ���
	public: 
		CityClass *next;
		
		/*
		
		���һ���Ƶ꣬ע�����������ĳ�����ж������ 
		���Ա�����CityClass���ʵ���ڷ��� 
		ע�⣬��ʹ��ͬһ������ͬ���Ƶ�Ҳ�����кܶ�
		��������û�в��� ֱ����Ӽ��� 
		��������Ƶ��ָ�� 
		
		*/
		HotelClass* addHotel(){
			HotelClass *tempPoint = new HotelClass();
			if(HotelList == NULL)  HotelList = tempPoint;
			else HotelListTail -> next = tempPoint;
			HotelListTail = tempPoint; 
			return tempPoint;
		}
		
		/*
		
		ɾ��һ���Ƶ꣬ע�����������ĳ�����ж���ɾ��
		���Ա�����Cityclass���ʵ���ڷ��� 
		������Ľӿڱ�����һ��HotelClass��ָ���Ծ�ȷɾ�� 
		����һ��bool�� ��ʾ�Ƿ�ɹ�ɾ��
		 
		*/
		bool deleteHotel(HotelClass *Input){
			HotelClass *Index = HotelList, *INext= HotelList->next;
			if(Index == Input){
				//����ͷɾ��
				HotelList = HotelList ->next;
				if(HotelListTail == Input) HotelListTail = NULL;
				free(Index); return true; 
			}
			while(Index != NULL){
				if(INext == Input) {
					Index -> next = INext ->next;
					if(INext == HotelListTail) HotelListTail = Index;//����βɾ�� 
					free(INext);
					return true;
				}
				else {
					Index = Index->next;
					if(INext != NULL) INext = INext->next;
				}
			}
			return false;
		}
		
		void printCityInfo(){
			cout<<name<<endl;
			HotelClass *Index = HotelList;
			while(Index != NULL){
				cout<<" -> ";
				Index->printInfo();
				Index = Index->next;
			}
			cout<<endl;
		} 
};
CityClass* CityList = NULL;//�ص�����ͷ
CityClass* CityListTail = NULL;//�ص�����β
 
/*

����һ�����У��������Ӧ������ڵ�(CityList)ָ��
��������� ����NULL 
�ӿڣ�������string 

*/
CityClass* findCity(string targetS){
	CityClass *Index = CityList; 
	if(Index != NULL) 
		while(Index != NULL && Index->name != targetS){
			Index = Index->next;
		}
	return Index; 
} 

/*

����һ���Ƶ� 
ע�� ���ؿ�����ͬ���ľƵ꣬����Ҫ��ͬ����ȫ��� 
�ӿڣ��Ƶ���string
�����һ��resultHotel������ɵ�����������ÿһ���ڵ㶼����һ��Hotel 
��������Ϊ findHotelList ,Ҳ��ͷ�ڵ�ָ�� 

*/ 
struct resultHotel{
	HotelClass *HotelPointer;
	resultHotel *next;
	CityClass *Super;//����һ���������ʸ��׽ڵ��ָ��
}*findHotelList,*findHotelTail;
 
/*

��findHotelList������������һ��InsertPoint��ָ��Ľڵ� 

*/
void resHotelInsert(HotelClass *InsertPoint,CityClass *Father){//��resultHotel����ڵ� 
	resultHotel *tempPoint = new resultHotel;
	tempPoint->HotelPointer = InsertPoint;
	tempPoint->next = NULL;
	tempPoint->Super = Father;
	if(findHotelList == NULL)
		findHotelList = tempPoint;
	else
		findHotelTail->next= tempPoint;
	findHotelTail = tempPoint;
}

void findHotel(string targetS){
	findHotelList =	findHotelTail = NULL; 
	CityClass *Index = CityList;
	while(Index != NULL){
		HotelClass *HIndex = Index->HotelList;// HIndex ö������һ���Ƶ�
		while(HIndex != NULL){
			if(HIndex -> name == targetS)
				resHotelInsert(HIndex,Index);
			HIndex= HIndex->next;	
		} 
	}
} 

/*

���findHotelList�е���Ϣ 

*/
void outputHotelFind(){
	resultHotel *Index = findHotelList;
	while(Index != NULL){
		cout<<Index->Super->name<<":";
		Index->HotelPointer->printInfo();
		Index = Index->next;
	} 
} 

/*

���һ�����У��ӿڣ�������
������в���������ӳ��� 
���ص���������е�ָ�� 

*/ 

CityClass* addCity(string InputS){
	CityClass *tempPoint = findCity(InputS);
	if(tempPoint == NULL){
		tempPoint = new CityClass;
		tempPoint -> name = InputS;
		tempPoint -> next = NULL; 
		if(CityList == NULL) CityList = tempPoint;
		else CityListTail -> next = tempPoint;
		CityListTail = tempPoint;
		
		tempPoint->HotelList = tempPoint->HotelListTail = NULL;
	}
	return tempPoint; 
} 

/*

ɾ��һ�����У��ӿڣ������� 
����һ��bool�ͱ�ʾ�Ƿ�ɹ�ɾ��
 
*/ 
bool deleteCity(string InputS){
	
} 


/*

��ȡ����
�����ļ�Ҫ��
��һ�б�ʾ������ ����������һ��������Ϣ
	
	����ÿ������ ��һ�г����� ������ֱ�ʾ�Ƶ����
	�����������Ƶ���Ϣ 
		
		����ÿ���Ƶ� ��һ������������Ϣ ������ֱ�ʾ������
		����������������Ϣ
			
			����ÿ������ ��һ����������Ļ�����Ϣ 

*/
void HotelLoadData(){
	freopen("HotelData.txt","r",stdin);
	string InputS; 
	int totCity=0; cin>> totCity;//������ 
	while(totCity--){
		cin>> InputS; 
		CityClass *Index = addCity(InputS);
		int totHotel=0; cin>> totHotel;//�Ƶ���
		while(totHotel--){
				HotelClass *HIndex = Index->addHotel();
				int totRoom=0; cin>> totRoom;//������ 
				while(totRoom--)
					HIndex->addRoom();
		} 
	} 
}

/*

�����û�����ɸѡ���ʵı��� 
�ӿڣ�������string ����int ����int 
���һ�� optionHotel�� ���飬�����пɹ�ѡ��ľƵ��Լ�����۸� 
����û��ѡ����������Ϊ���򲻷��㣬���Ҳ�������������
�ǿռ临�Ӷ� ��ȡʱ�临�ӶȺͱ�̸��Ӷȵ����� 

����ǰ�����޺��ʵľƵ꣨�޾Ƶ� �� �����������ľƵ꣩ �����Ӧ��ʾ 
�����ں��ʵľƵ꣬��ĳ��˳������ʺϵľƵ��Լ�����Ҫ�ļ�Ǯ
��ͬһ�Ƶ���ڲ�ͬ�Ľ������ʱ�����ȿ��Ǽ�Ǯ��͵�

������ĳ��˳��ָ���ǣ���Ĭ�ϣ����� ������Ĭ�ϣ��۸�������
����ָ���Ǽ۸�˳�����к���������м��λ�ȽϺ���
Ȼ��һǰһ�����������ľƵ�����
 
*/

struct optionHotel{
	HotelClass *HotelPointer;//ָ��Ƶ�
	int price;//��Ǯ (��������) 
}HotelOptions[30]; 

int totOption = 0;//���пɹ�ѡ��ľƵ��� 

/*

calcMinPrice ������ڸ����Ƶ��ڿͻ�ָ�������������ٴ��ۻ���
int �ͷ��أ��������ٴ��ۻ��ѣ�Ĭ�ϴ���0.�������ֵΪ-1
��˵���˾Ƶ�û�к��ʵĿͷ�����ס �ϲ�˵�������Ϊ���ݽ�����һ������ 

��̬�滮˼�룬��f(n)��ʾn������ס��Ҫ����С����
ö�ٷ��䣬�跿��i��סCi�ˣ��۸�Pi ,��ô�������е�i<=Ci,��Ҫ�Ƚ�f(i)��Pi��ֵ
ʵ���������Ϊ��i����ס����ΪCi���۸�ΪPi�ķ���Ļ��������Ƿ��С
��������i�����f(i+Ci)<f(i)+Pi,����f(i+Ci)��ֵ 
ʵ���������Ϊ������һ�����ŵķ���ʹ��סi+Ci���˵Ļ�Ǯ������

**Ȼ��������һ�������ص����� ����ֻ��һ�����˼� �۸�Ϊ108 ��������˫�˼��Ҽ۸������ף���ǧ�� 
����������������в���������ס3�� ����С�۸�Ϊ316,�������ǲ��Ե� ԭ������
����f(i+Ci)ʱ�����п���f(i)���Ѿ����¹��˵�ֵ���ȼ������˸÷����Ժ�����һ�� �ǲ��Ե�
�������ʹ�ù����������滻����cnt=0��ÿ����1���cnt��ʾ��ǰ�����������
ÿ�θ�����cnt^1��ֵ����cnt��ֵ �����Ͳ������ 
 
*/
int calcMinPrice(HotelClass *Index,int peopleNum,int dayNum){
	int f[2][20],ret=2147483647;
	//���ʮ����ͬʱ��ס������Я�̹�����
	//���ܴ���һ�ֹ�ס���������һ�Ǯ���ٵķ��� ���Ҫ��Ӽ�λ 
	f[0][0]=f[1][0]=0;
	for(int i=1;i<=19;i++) f[0][i]=f[1][i]=200000000; 
	GuestRoomClass *ite = Index->RoomList;
	int cnt=0;
	while(ite !=NULL){
	//	ite->printInfo();
		for(int i=1;i<20-ite->capacity;i++){
			if(i<=ite->capacity) f[cnt][i]=min(f[cnt^1][i],ite->price);
			if(f[cnt^1][i]+ite->price<f[cnt^1][i+ite->capacity])
				f[cnt][i+ite->capacity]=f[cnt^1][i]+ite->price;
			if(i>=peopleNum) ret=min(ret,f[cnt][i]);
		}
		ite=ite->next;
//		for(int i=1;i<20;i++) cout<<f[cnt][i]<<' ';cout<<endl;
		cnt^=1;
	}
	/*for(int pNum=1;pNum<15;pNum++){
		GuestRoomClass *ite = Index->RoomList;
		while(ite != NULL){
			f[pNum] = min (f[pNum] , f[max (pNum-ite->capacity, 0)]+ite->price);
			ite=ite->next;
		}
		if(pNum>=peopleNum)
			ret = min(ret,f[pNum]);
	}*/
	if(ret > 100000000) ret=-1;
	
//	cout<<"============================="<<endl;
	return ret; 
}

void findOption(string cityString,int peopleNum,int dayNum){
	totOption=0;
	CityClass *Index = findCity(cityString);
	if(Index != NULL) {
		HotelClass *HIndex = Index -> HotelList;
		while(HIndex != NULL){//�����Ƶ��б� 
			//��ʱHIndex ָ�����һ���Ƶ�
			
			int retNum = calcMinPrice(HIndex,peopleNum,dayNum);
			if(retNum){
				++totOption;
				HotelOptions[totOption].HotelPointer = HIndex;
				HotelOptions[totOption].price = retNum;
			}
			HIndex = HIndex -> next;	 
		}
	} 
} 
/*

��struct optionHotel��HotelOptions�������� 
�ؼ��ֱַ�Ϊ �۸�ӵ͵��ߣ� �۸�Ӹߵ��� ����������
��ν�����Ѿ��������и������壬 ����ʹ��algorithm ��� qsort������������ 
��Ҫ���cmp�����������Ƚϣ���Ϊ�Ƿ񽻻�������
 
*/

int cmpPriceUp(const void *a,const void *b){
	optionHotel x =*(optionHotel *)a;
	optionHotel y =*(optionHotel *)b;
	return x.price > y.price; 
} 

int cmpPriceDown(const void *a,const void *b){
	optionHotel x =*(optionHotel *)a;
	optionHotel y =*(optionHotel *)b;
	return x.price < y.price; 
} 

void sortByPriceUp(){
	qsort(HotelOptions+1,totOption,sizeof(optionHotel),cmpPriceUp);
}

void sortByPriceDown(){
	qsort(HotelOptions+1,totOption,sizeof(optionHotel),cmpPriceDown);
}

void sortDefault(){
	sortByPriceUp();
	//����������
	vector<optionHotel> tempArray;
	int i=totOption/2,j=1+totOption/2;
	//���м���������չ 
	while(i>=1 || j<=totOption){
		if(i>=1) tempArray.push_back(HotelOptions[i--]);
		if(j<=totOption)tempArray.push_back(HotelOptions[j++]);		
	}
	for(i=1;i<=totOption;i++)
		HotelOptions[i]=tempArray[i-1];
}

/*

�Ƶ�ģ������ 

���ǵ��������ַ� ռ�����ֽ� ��������һ����
���� ��string s="����", ��ô s[0]s[1] Ϊ '��'��s[2]s[3]Ϊ'��' 
���ڿ��������ַ������ƶȱȽϣ���ǰһ���ַ�������i1,i2 ��һ��Ϊj1,j2 
���������������� (��ǰ����)���ڰ�ƴ������ /(��������)���ڰ�ƫ�Բ������� 
��ǰ����Ҫ�ǳ����֣���������Ҫ����Ƨ�֡��������ھƵ������ϵ��ִ���ǳ����֣�Ҳ���ڿ�ǰ�����飬
����i1��j1�Ĳ��Ӱ�����Ӵ�i2,j2�Ĳ��Ӱ������С��

����������Ȩ��w1,w2, dif = w1*|i1-j1| + w2*|i2-j2| ���������������ַ��Ĳ���� 
dif Խ�� ˵�����Խ��ԽС��˵��Խ���ơ������Ե���dif��ȡֵ��[0,+oo)
������ָ������ӳ���ƥ���match,��match = k^dif,(0<k<1),
kȷ��match���½��ٶ� ��ӳ���match ȡֵ�� (0~1],��ȫһ���������ַ�match=1 

���Ǽ��������ַ����е�ÿһ���ַ��Ͷ�Ӧ�Ƶ�����Ƶ�ƥ��ȵ�ƽ��ֵ��Ϊ�þƵ�������ƥ���
���ǵ�����Ӱ�죬���������Ƿ��г���������������г���������Ӧ���ȿ��Ǹó��еľƵ�
Ҳ����˵ ���� ��ռ�ı��طǳ���������ó���CityMatchҲ�Ǵ���(0,1]
Ȼ�� CityMatch��ȡֵ(��ȥ����)ֻ��������������1 �� 0.5 �� 0 
�������1��0.5��Ӧ����߳��еı��أ������������򲿷ֳ������� 
��CityMatch�����ţ���ΪȨ���ھƵ�ƥ�����ˣ���Ϊ���յ�ƥ��Ƚ�������ý�����򼴿� 
	
exp:
 
	string s="��������";//������ 
	fuzzySearch(s);
	outputFuzzy();

*/
struct fuzzyNode{
	HotelClass *Node;
	double sMark;//���ƶ� 
};
vector<fuzzyNode> fuzzyRes;

bool cmp_sMark(fuzzyNode L,fuzzyNode R){
	return L.sMark > R.sMark;
}

double calcSimilarity(string L,string R){
	//�����Ĵ���
	int Ll=L.length(),Rl=R.length();
	//cout<<Ll<<' '<<Rl<<endl;
	double w1=0.65,w2=0.35; 
	double totM=0.0;
	for(int i=0;i*2<Ll;i++){//Lƥ�䴮 Rģʽ�� 
		double maxMatch=0;
		int i1=(int)L[i*2],i2=(int)L[i*2+1];
		for(int j=0;j*2<Rl;j++){
			int j1=(int)R[j*2],j2=(int)R[j*2+1];
			double dif = w1*abs(i1-j1) + w2*abs(i2-j2);
			//cout<<i1<<' '<<i2<<' '<<j1<<' '<<j2<<endl;
			double mat = pow(0.6,dif);
			maxMatch = mat>maxMatch?mat:maxMatch;
		}//cout<<maxMatch<<endl;
		totM+=maxMatch; 
	}
	totM=totM*2/(double)Ll;//��������Ӱ��
	//cout<<L<<' '<<R<<' '<<totM<<endl;cout<<"======"<<endl;
	return totM; 
} 

void fuzzySearch(string InputS){
	CityClass *CIndex = CityList;
	double Match = 0;
	while(CIndex != NULL){//ö�ٳ���
		double CityMatch = 0;
		HotelClass *HIndex = CIndex -> HotelList; 
		CityMatch = sqrt(calcSimilarity(CIndex -> name,InputS));//����ƥ��� 
		while(HIndex != NULL){//ö�پƵ� ����Ƶ�ƥ��� 
			double HotelMatch=calcSimilarity(InputS , HIndex -> name);
			Match=CityMatch*HotelMatch;
			fuzzyRes.push_back((fuzzyNode){HIndex,Match}); 
			HIndex = HIndex ->next; 
		}
		CIndex = CIndex->next;
	} 
	sort(fuzzyRes.begin(),fuzzyRes.end(),cmp_sMark);
}

void outputFuzzy(){
	cout<<"���ǲ����ڲ��ң�";
	fuzzyRes[0].Node->printInfo();
	cout<<endl<<"�������(���ƶ�ǰ10):"<<endl; 
	for(int i=0;i<10;i++){
		cout<< fuzzyRes[i].Node->name<<" ���ƶ�: "<<fuzzyRes[i].sMark<<endl;
	}
}


