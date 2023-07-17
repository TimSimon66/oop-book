#include <bits/stdc++.h>
#include <cstddef>
#include <vector>
#include <string>
using namespace std;

class Sach{
	public:
		virtual void Nhap() = 0;
		virtual void Xuat() = 0;
		virtual void Xuat_ten_Sach() = 0;
		
		string ten_sach;
		int nam_sach;
		float gia_sach;
};

class Truyentranh : public Sach{
	public:
		void Nhap(){
			cin.ignore();
			cout << "Nhap ten sach : ";
			getline(cin, ten_sach);
			cout << "Nhap nam sang tac : ";
			cin >> nam_sach;
			cout << "Nhap gia ban : ";
			cin >> gia_sach;
		}
		
		void Xuat(){
			cout << "Ten sach la : " << ten_sach << endl;
			cout << "Nam sang tac la : " << nam_sach << endl;
			cout << "Gia sach la : " << gia_sach << endl;
		}
		
		void Xuat_ten_Sach(){
			cout << ten_sach;
		}
};

class Tapchi : public Sach{
	public:
		void Nhap(){
			cin.ignore();
			cout << "Nhap ten sach : ";
			getline(cin, ten_sach);
			cout << "Nhap nam sang tac : ";
			cin >> nam_sach;
			cout << "Nhap gia ban : ";
			cin >> gia_sach;
		}
		
		void Xuat(){
			cout << "Ten sach la : " << ten_sach << endl;
			cout << "Nam sang tac la : " << nam_sach << endl;
			cout << "Gia sach la : " << gia_sach << endl;
		}
		
		void Xuat_ten_Sach(){
			cout << ten_sach;
		}
};

class Tieuthuyet : public Sach{
	public:
		void Nhap(){
			cin.ignore();
			cout << "Nhap ten sach : ";
			getline(cin, ten_sach);
			cout << "Nhap nam sang tac : ";
			cin >> nam_sach;
			cout << "Nhap gia ban : ";
			cin >> gia_sach;
		}
		
		void Xuat(){
			cout << "Ten sach la : " << ten_sach << endl;
			cout << "Nam sang tac la : " << nam_sach << endl;
			cout << "Gia sach la : " << gia_sach << endl;
		}
		
		void Xuat_ten_Sach(){
			cout << ten_sach;
		}
};

class ListSach{
	private:
		vector <Sach*> dsSach;
		
		public:
			
			void Hien_Thi_Ten_Sach(){
				int so_luong;
				so_luong = dsSach.size();
				cout << "\nSo luong sach hien co la : " << so_luong;
				for(int i = 0; i < dsSach.size(); i++){
					cout << "\nTen sach thu " << i + 1 << " ";
					dsSach[i]->Xuat_ten_Sach();
				}
			}
			
			void Xoa_Sach(){
				string ten_sach_xoa;
				int index = -1;
				cout << "\nNhap ten sach muon xoa : ";
				cin >> ten_sach_xoa;
				
				for(int i = 0; i < dsSach.size(); i++){
					if(dsSach[i]->ten_sach == ten_sach_xoa){
						index = i;
						break;
					}
				}
				
				if(index != -1){
					delete dsSach[index];
  					dsSach.erase(dsSach.begin() + index);
            		cout << "Xoa sach thanh cong" << endl;
				}
				else{
					cout << "Khong tim thay sach" << endl;
				}
			}
			
			void Nhap(){
				int n;
				cout << "Nhap so luong sach : ";
				cin >> n;
				cin.ignore();
				for(int i = 0; i < n; i++){
					cout << "\nNhap sach " << i + 1 << endl;
					cout << "Chon the loai sach muon nhap" << endl;
					cout << "1.Truyen tranh" << endl;
					cout << "2.Tap chi" << endl;
					cout << "3. Tieu thuyet" << endl;
					int choice;
					cout << "Lua chon cua ban la : ";
					cin >> choice;
					
					Sach *sach = NULL;
					switch(choice){
						case 1:
							sach = new Truyentranh();
							break;
						case 2:
							sach = new Tapchi();
							break;
						case 3:
							sach = new Tieuthuyet();
							break;
						default:
							cout << "Lua chon khong dung" << endl;
							i--;
							continue;
					}
					sach->Nhap();
					dsSach.push_back(sach);
				}
			}
			
			void Xuat(){
				cout << "\nDanh sach sach la" << endl;
				for(int i = 0; i < dsSach.size(); i++){
					cout << "\nThong tin sach " << i + 1 << endl;
					dsSach[i]->Xuat();
				}
			}
};

int main(){
	ListSach ds;
	ds.Nhap();
	ds.Xuat();
	ds.Hien_Thi_Ten_Sach();
	ds.Xoa_Sach();
	ds.Hien_Thi_Ten_Sach();
}
