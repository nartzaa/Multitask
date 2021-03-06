#define LED1 13
#define LED2 12

unsigned long last1, last2;

void setup(){
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
}

void loop(){
    if (millis() - last1 >= 500){ 
        last1 = millis();
        digitalWrite(LED1, !digitalRead(LED1));
    }
    if (millis() - last2 >= 300){
        last2 = millis();
        digitalWrite(LED2, !digitalRead(LED2));
    }
}

/*
ส่วนสำคัญของโค้ดที่เกี่ยวข้องกับการทำงานแบบมัลติทาสกิ้งมีดังนี้
บรรทัดที่ 4 ประกาศตัวแปร last1 และ last2 เพื่อเก็บค่าเวลาที่โปรแกรมในกระบวนการของหลอด LED ดวงแรกและดวงที่สองทำงาน
บรรทัดที่ 12 ดึงค่าเวลาปัจจุบันมาจากฟังก์ชั่ millis() แล้วนำมาหักลบกับตัวแปร last1 แล้วเปรียบเทียบว่าเวลาผ่านไปครบ หรือมากกว่า 500 มิลิวินาทีแล้วหรือยัง ถ้าผ่านไปครบแล้ว ให้ทำคำสั่งในปีกกาของ if
บรรทัดที่ 13 นำค่าเวลาปัจจุบันจากฟังก์ชั่น millis() มาเก็บลงตัวแปร last1 เพื่ออัพเดทเวลาที่โค้ดทำงานล่าสุดใหม่
บรรทัดที่ 14 สลับสถานะของหลอด LED ดวงแรก
บรรทัดที่ 16 ดึงค่าเวลาปัจจุบันมาจากฟังก์ชั่ millis() แล้วนำมาหักลบกับตัวแปร last2 แล้วเปรียบเทียบว่าเวลาผ่านไปครบ หรือมากกว่า 300 มิลิวินาทีแล้วหรือยัง ถ้าผ่านไปครบแล้ว ให้ทำคำสั่งในปีกกาของ if
บรรทัดที่ 17 นำค่าเวลาปัจจุบันจากฟังก์ชั่น millis() มาเก็บลงตัวแปร last1 เพื่ออัพเดทเวลาที่โค้ดทำงานล่าสุดใหม่
บรรทัดที่ 18 สลับสถานะของหลอด LED ดวงที่สอง
สาเหตุที่ครบเวลาที่กำหนดใน if แล้วจะต้องมีการอัพเดทตัวแปร last1 last2 ทันที เพราะหลังจากทำโปรแกรมไปแล้วอาจจะทำให้ค่าเวลาคลาดเคลื่อนจากค่าที่ได้ใน millis() ใน if แล้วจะส่งผลให้โค้ดโปรแกรมทำงานตามเวลาผิดพลาดไป
*/