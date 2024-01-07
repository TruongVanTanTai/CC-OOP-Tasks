#include <iostream>
#include <sstream>
#include <vector>
#include <string>

struct Date {
    int ngay, thang, nam;
};

Date getDate(std::string ngayVao) {
    std::stringstream ss(ngayVao);
    std::string tmp;
    std::vector<int> v;
    while(getline(ss, tmp, '/')) {
        v.push_back(stoi(tmp));
    }
    Date date;
    date.ngay = v[0];
    date.thang = v[1];
    date.nam = v[2];
    return date;
}

class Canbo {
    public:
        Canbo() {
            this->maCanBo = "Unknown";
            this->hoTen = "Unknown";
            this->ngayVao.ngay = 0;
            this->ngayVao.thang = 0;
            this->ngayVao.nam = 0;
        }
        Canbo(std::string maCanBo, std::string hoTen, std::string ngayVao) {
            this->maCanBo = maCanBo;
            this->hoTen = hoTen;
            this->ngayVao = getDate(ngayVao);
        }
        void setMaCanBo(std::string maCanBo) {
            this->maCanBo = maCanBo;
        }
        std::string getMaCanBo() {
            return this->maCanBo;
        }
        void setHoTen() {
            this->hoTen = hoTen;
        }
        std::string getHoTen() {
            return this->hoTen;
        }
        void setNgayVao(std::string ngayVao) {
            this->ngayVao = getDate(ngayVao);
        }
        Date getNgayVao() {
            return this->ngayVao;
        }
        void input() {
            std::cout << "\tMa can bo: ";
            getline(std::cin, this->maCanBo);
            std::cout << "\tHo ten: ";
            getline(std::cin, this->hoTen);
            std::cout << "\tNgay vao co quan: ";
            std::string ngayVao;
            getline(std::cin, ngayVao);
            this->ngayVao = getDate(ngayVao);
        }
        void display() {
            std::cout << "\tMa can bo: " << this->maCanBo << "\n";
            std::cout << "\tHo ten: " << this->hoTen << "\n";
            std::cout << "\tNgay vao co quan: " << this->ngayVao.ngay << "/" << this->ngayVao.thang << "/" << this->ngayVao.nam << "\n";
        }
        bool operator >(Canbo &other) {
            if(this->ngayVao.nam > other.ngayVao.nam) {
                return true;
            }
            else if(this->ngayVao.nam < other.ngayVao.nam) {
                return false;
            }
            else {
                if(this->ngayVao.thang > other.ngayVao.thang) {
                    return true;
                }
                else if(this->ngayVao.thang < this->ngayVao.thang) {
                    return false;
                }
                else {
                    if(this->ngayVao.ngay > this->ngayVao.ngay) {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
    private:
        std::string maCanBo;
        std::string hoTen;
        Date ngayVao;
};

class Giangvien : public Canbo {
    public:
        Giangvien() {
            this->donVi = "Unknown";
            this->heSoLuong = 0;
            this->phuCapChucVu = 0;
        }
        Giangvien(std::string maCanBo, std::string hoTen, std::string ngayVao, std::string donVi, float heSoLuong, float phuCapChucVu) : Canbo(maCanBo, hoTen, ngayVao) {
            this->donVi = donVi;
            this->heSoLuong = heSoLuong;
            this->phuCapChucVu = phuCapChucVu;
        }
        void setDonVi(std::string donVi) {
            this->donVi = donVi;
        }
        std::string getDonVi() {
            return this->donVi;
        }
        void setHeSoLuong(int heSoLuong) {
            this->heSoLuong = heSoLuong;
        }
        int getHeSoLuong() {
            return this->heSoLuong;
        }
        void setPCCV(float phuCapChucVu) {
            this->phuCapChucVu = phuCapChucVu;
        }
        float getPCCV() {
            return this->phuCapChucVu;
        }
        float getSalary() {
            return this->heSoLuong * 1490000 + this->phuCapChucVu;
        }
        void input() {
            Canbo::input();
            std::cout << "\tDon vi: ";
            getline(std::cin, this->donVi);
            std::cout << "\tHe so luong: ";
            std::cin >> this->heSoLuong;
            std::cout << "\tPhu cap chuc vu: ";
            std::cin >> this->phuCapChucVu;
            std::cin.ignore();
        }
        void display() {
            Canbo::display();
            std::cout << "\tDon vi: " << this->donVi << "\n";
            std::cout << "\tHe so luong: " << this->heSoLuong << "\n";
            std::cout << "\tPhu cap chuc vu: " << this->phuCapChucVu << "\n";
            std::cout << "\tTien luong: " << this->getSalary() << "\n";
        }
    private:
        std::string donVi;
        float heSoLuong;
        float phuCapChucVu;
};

int main() {
    std::cout << "Nhap vao so luong giang vien: ";
    int n;
    std::cin >> n;
    std::cin.ignore();
    Giangvien teacher[n];
    for(int i = 0; i < n; i++) {
        std::cout << "Nhap vao thong tin cho giang vien " << i + 1 << ":\n";
        teacher[i].input();
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(teacher[i] > teacher[j]) {
                std::swap(teacher[i], teacher[j]);
            }
        }
    }
    std::cout << "Danh sach giang vien tang dan theo tieu chi ngay vao co quan:\n";
    for(int i = 0; i < n; i++) {
        std::cout << "Giang vien " << i + 1 << ":\n";
        teacher[i].display();
    }
    float sumSalary = 0;
    for(int i = 0; i < n; i++) {
        sumSalary += teacher[i].getSalary();
    }
    std::cout << "Luong trung binh cua giang vien la: " << sumSalary / n << "\n";
    std::vector<std::string> dv;
    for(int i = 0; i < n; i++) {
        bool check = false;
        for(int j = 0; j < dv.size(); j++) {
            if(teacher[i].getDonVi() == dv[j]) {
                check = true;
            }
        }
        if(check == false) {
            dv.push_back(teacher[i].getDonVi());
        }
    }
    std::cout << "Bang luong cua cac giang vien theo tung don vi:\n";
    for(int i = 0; i < dv.size(); i++) {
        std::cout << "- Don vi: " << dv[i] << "\n";
        for(int j = 0; j < n; j++) {
            if(teacher[j].getDonVi() == dv[i]) {
                std::cout << "Giang vien:\n";
                teacher[j].display();
            }
        }
    }
    return 0;
}