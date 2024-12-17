#include<iostream>
#include<iomanip> // For using setw(), setprecision(), fixed
using namespace std;

int main(){
    double initialLoan, interestRate, annualPayment; // ตัวแปรสำหรับข้อมูลจากผู้ใช้

    // รับค่าข้อมูลจากผู้ใช้
    cout << "Enter initial loan: ";
    cin >> initialLoan;
    cout << "Enter interest rate per year (%): ";
    cin >> interestRate;
    cout << "Enter amount you can pay per year: ";
    cin >> annualPayment;

    // แปลงดอกเบี้ยจากเปอร์เซ็นต์เป็นทศนิยม
    interestRate = interestRate / 100.0;

    // พิมพ์หัวตาราง
    
    cout << setw(13) << left << "EndOfYear#";
    cout << setw(13) << left << "PrevBalance";
    cout << setw(13) << left << "Interest";
    cout << setw(13) << left << "Total";
    cout << setw(13) << left << "Payment";
    cout << setw(13) << left << "NewBalance";
    cout << "\n";

    // กำหนดความแม่นยำของทศนิยม
    cout << fixed << setprecision(2);

    // คำนวณหนี้ในแต่ละปี
    double prevBalance = initialLoan;
    double interest, total, payment, newBalance;
    int year = 1;

    while (prevBalance > 0.0) {
        // คำนวณดอกเบี้ยและยอดรวม
        interest = prevBalance * interestRate;
        total = prevBalance + interest;

        // ตรวจสอบว่าการชำระเงินครั้งสุดท้ายควรเป็นเท่าไร
        payment = (total < annualPayment) ? total : annualPayment;
        newBalance = total - payment;

        // แสดงผลข้อมูลในแต่ละปี
        cout << setw(13) << left << year++;
        cout << setw(13) << left << prevBalance;
        cout << setw(13) << left << interest;
        cout << setw(13) << left << total;
        cout << setw(13) << left << payment;
        cout << setw(13) << left << newBalance;
        cout << "\n";

        // อัปเดตยอดหนี้คงเหลือ
        prevBalance = newBalance;
    }

    return 0;
}