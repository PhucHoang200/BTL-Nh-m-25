#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tuthien {
	int stt;
    char ten[50];
    char diachi [20];
    char ngayungho[20];
    float sotien;
    struct tuthien* next;
} Tuthien;

Tuthien* head = NULL;
void clrscr() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void add(Tuthien *tuthien) {
    Tuthien* new_tuthien = (Tuthien*)malloc(sizeof(Tuthien));
	new_tuthien->stt = 0;
    printf("Nhap ho va ten: ");
    fflush(stdin);
    gets(new_tuthien->ten);
    printf("Nhap dia chi: ");
    fflush(stdin);
    gets(new_tuthien->diachi);
    printf("Nhap ngay ung ho:(dd/mm/yy) ");
    fflush(stdin);
    gets(new_tuthien->ngayungho);
    printf("Nhap so tien: ");
    scanf("%f", &new_tuthien->sotien);
    new_tuthien->next = NULL;

    if (head == NULL) {
        head = new_tuthien;
        new_tuthien->stt=1;
    } else {
        Tuthien* node = head;
        while (node->next != NULL) {
            node = node->next;
        }
        new_tuthien->stt = node->stt + 1;
        node->next = new_tuthien;
    }
    printf("Nhap thanh cong!\n");
}
void edit(Tuthien *tuthien) {
    int stt;
    printf("Nhap STT nguoi can sua: ");
    scanf("%d", &stt);
    Tuthien* node = head;
    while (node != NULL) {
        if (node->stt == stt) {
            printf("Nhap ho ten thay the: ");
            getchar();
            fflush(stdin);
            gets(node->ten);
            printf("Nhap dia chi: ");
            fflush(stdin);
            gets(node->diachi);
            printf("Nhap ngay ung ho (dd/mm/yy): ");
            fflush(stdin);
            gets(node->ngayungho);
            printf("Nhap so tien: ");
            scanf("%f", &node->sotien);
            printf("Cap nhat thanh cong!\n");
            return;
        }
        node = node->next;
    }
    printf("Khong ton tai.\n");
}
void print(Tuthien *tuthien) {
    printf("-------------------------------DANH SACH TU THIEN--------------------------------\n\n");
    printf("+-----+---------------------------+---------------+--------------+------------------+\n");
    printf("| %-3s | %-25s | %-13s | %-12s | %-16s |\n", "STT", "Ho va ten", "Dia chi", "Ngay ung ho", "So tien");
    printf("+-----+---------------------------+---------------+--------------+------------------+\n");

    Tuthien* node = head;
    while (node != NULL) {
        printf("| %-3d | %-25s | %-13s | %-12s | %-16.2f |\n", node->stt, node->ten, node->diachi, node->ngayungho, node->sotien);
        node = node->next;
    }
    printf("+-----+---------------------------+---------------+--------------+------------------+\n");
}
void xoa(Tuthien *tuthien){
    int stt;
    printf("Nhap STT nguoi can xoa: ");
    scanf("%d", &stt);
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }
    if (head->stt == stt) {
        Tuthien* temp = head;
        head = head->next;
        free(temp);
        printf("Da xoa thanh cong!\n");
        Tuthien* node = head;
        while (node != NULL) {
            node->stt--;
            node = node->next;
        }
        return;
    }
    Tuthien* node = head;
    int index = 0;
    while (node->next != NULL) {
        index++;
        if (node->next->stt == stt) {
            Tuthien* temp = node->next;
            node->next = node->next->next;
            free(temp);
            printf("Da xoa thanh cong!");
            Tuthien* p = node->next;
            while (p != NULL) {
                p->stt--;
                p = p->next;
            }
            return;
        }
        node = node->next;
    }
    printf("Khong tim thay STT can xoa.\n");
}
void search_stt(Tuthien *tuthien) {
    int stt;
    printf("Nhap STT nguoi can tim kiem: ");
    scanf("%d", &stt);
	
    Tuthien* node = head;
    while (node != NULL) {
        if (node->stt == stt) {
            printf("Thong tin nguoi co STT %d:\n", stt);
 			printf("+-----+---------------------------+---------------+--------------+------------------+\n");
    		printf("| %-3s | %-25s | %-13s | %-12s | %-16s |\n", "STT", "Ho va ten", "Dia chi", "Ngay ung ho", "So tien");
    		printf("+-----+---------------------------+---------------+--------------+------------------+\n");
    		printf("| %-3d | %-25s | %-13s | %-12s | %-16.2f |\n", node->stt, node->ten, node->diachi, node->ngayungho, node->sotien);
    		printf("+-----+---------------------------+---------------+--------------+------------------+\n");
            return;
        }
        node = node->next;
    }

    printf("Khong tim thay STT can tim kiem.\n");
}
void search_ten(Tuthien *tuthien) {
	char ten[50];
    printf("Nhap ten nguoi can tim kiem: ");
    fflush(stdin);
    gets(ten);
    Tuthien* node = head;
    printf("Danh sach nguoi co ten %s:\n",ten);
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
   	printf("| %-3s | %-25s | %-13s | %-12s | %-16s |\n", "STT", "Ho va ten", "Dia chi", "Ngay ung ho", "So tien");
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	int dem=0;
    while (node != NULL) {
        if (strcmp(node->ten, ten) == 0) {
      		printf("| %-3d | %-25s | %-13s | %-12s | %-16.2f |\n", node->stt, node->ten, node->diachi, node->ngayungho, node->sotien);
      		dem++;
        }
        node = node->next;
    }
    printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	if(dem==0){
    printf("Khong tim thay ten nguoi can tim kiem.\n");
}}

void search_diachi(Tuthien *tuthien) {
	char diachi[50];
    printf("Nhap dia chi nguoi can tim kiem: ");
    fflush(stdin);
    gets(diachi);
    printf("Danh sach nguoi co dia chi %s:\n",diachi);
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	printf("| %-3s | %-25s | %-13s | %-12s | %-16s |\n", "STT", "Ho va ten", "Dia chi", "Ngay ung ho", "So tien");
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
    Tuthien* node = head;
    int dem=0;
    while (node != NULL) {
        if (strcmp(node->diachi, diachi) == 0) {
            printf("| %-3d | %-25s | %-13s | %-12s | %-16.2f |\n", node->stt, node->ten, node->diachi, node->ngayungho, node->sotien);
            dem++;
        }
        node = node->next;
    }
    printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	if(dem==0){
    printf("Khong tim thay dia chi can tim kiem.\n");
}}
void search_sotien(Tuthien *tuthien) {
    float sotien;
    printf("Nhap so tien can tim kiem: ");
    scanf("%f", &sotien);
    printf("Danh sach nguoi co dia chi %f:\n",sotien);
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	printf("| %-3s | %-25s | %-13s | %-12s | %-16s |\n", "STT", "Ho va ten", "Dia chi", "Ngay ung ho", "So tien");
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
    Tuthien* node = head;
    int dem=0;
    while (node != NULL) {
        if (node->sotien == sotien) {
			printf("| %-3d | %-25s | %-13s | %-12s | %-16.2f |\n", node->stt, node->ten, node->diachi, node->ngayungho, node->sotien);
            dem++;
        }
        node = node->next;
    }
    printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	if(dem==0){
    printf("Khong tim thay so tien can tim kiem.\n");
}}
void sapxeptheoten(Tuthien *tuthien) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Tuthien* node = head;
    int n = 0;
    while (node != NULL) {
        n++;
        node = node->next;
    }

    for (int i = 0; i < n - 1; i++) {
        node = head;
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(node->ten, node->next->ten) > 0) {
                Tuthien* temp = node->next;
                node->next = temp->next;
                temp->next = node;
                if (node == head) {
                    head = temp;
                    node = head;
                }
                else {
                    Tuthien* prevNode = head;
                    while (prevNode->next != node) {
                        prevNode = prevNode->next;
                    }
                    prevNode->next = temp;
                    node = temp;
                }
            }
            else {
                node = node->next;
            }
        }
    }
    printf("Danh sach sau khi sap xep:\n");
    print(tuthien);
}
void sapxeptheodiachi(Tuthien *tuthien) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Tuthien* node = head;
    int n = 0;
    while (node != NULL) {
        n++;
        node = node->next;
    }

    for (int i = 0; i < n - 1; i++) {
        node = head;
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(node->diachi, node->next->diachi) > 0) {
                Tuthien* temp = node->next;
                node->next = temp->next;
                temp->next = node;
                if (node == head) {
                    head = temp;
                    node = head;
                }
                else {
                    Tuthien* prevNode = head;
                    while (prevNode->next != node) {
                        prevNode = prevNode->next;
                    }
                    prevNode->next = temp;
                    node = temp;
                }
            }
            else {
                node = node->next;
            }
        }
    }
    printf("Danh sach sau khi sap xep:\n");
    print(tuthien);
}
void sapxepsotien(Tuthien *tuthien) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Tuthien* node = head;
    int n = 0;
    while (node != NULL) {
        n++;
        node = node->next;
    }

    for (int i = 0; i < n - 1; i++) {
        node = head;
        for (int j = 0; j < n - i - 1; j++) {
            if (node->sotien > node->next->sotien) {
                Tuthien* temp = node->next;
                node->next = temp->next;
                temp->next = node;
                if (node == head) {
                    head = temp;
                } else {
                    Tuthien* prev = head;
                    while (prev->next != node) {
                        prev = prev->next;
                    }
                    prev->next = temp;
                }
                node = temp;
            }
            node = node->next;
        }
    }

    printf("Danh sach sau khi sap xep:\n");
    print(tuthien);
}
void sapxepSTT(Tuthien *tuthien) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Tuthien* node = head;
    int n = 0;
    while (node != NULL) {
        n++;
        node = node->next;
    }

    for (int i = 0; i < n - 1; i++) {
        node = head;
        for (int j = 0; j < n - i - 1; j++) {
            if (node->stt > node->next->stt) {
                Tuthien* temp = node->next;
                node->next = temp->next;
                temp->next = node;
                if (node == head) {
                    head = temp;
                } else {
                    Tuthien* prev = head;
                    while (prev->next != node) {
                        prev = prev->next;
                    }
                    prev->next = temp;
                }
                node = temp;
            }
            node = node->next;
        }
    }

    printf("Danh sach sau khi sap xep:\n");
    print(tuthien);
}
void thongke(Tuthien* tuthien) {
    if (tuthien == NULL) {
        printf("Danh sach rong.");
        return;
    }

    float tongtien = 0;
    Tuthien* node = head;
    Tuthien* nguoiunghonhieunhat = head;
    Tuthien* nguoiunghoitnhat = head;

    while (node != NULL) {
        tongtien += node->sotien;

        if (node->sotien > nguoiunghonhieunhat->sotien) {
            nguoiunghonhieunhat = node;
        }

        if (node->sotien < nguoiunghoitnhat->sotien) {
            nguoiunghoitnhat = node;
        }

        node = node->next;
    }

    printf("---TONG SO TIEN----: %f\n", tongtien);
    printf("----------------NGUOI UNG HO TIEN NHIEU NHAT-------------------\n") ;
	printf("+-----+---------------------------+---------------+--------------+------------------+\\nn");
	printf("| %-3s | %-25s | %-13s | %-12s | %-16s |\n", "STT", "Ho va ten", "Dia chi", "Ngay ung ho", "So tien");
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	printf("| %-3d | %-25s | %-13s | %-12s | %-16.2f |\n", nguoiunghonhieunhat->stt, nguoiunghonhieunhat->ten, nguoiunghonhieunhat->diachi,nguoiunghonhieunhat->ngayungho, nguoiunghonhieunhat->sotien);
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	printf("-----------------NGUOI UNG HO TIEN IT NHAT-----------------\n" );
	printf("+-----+---------------------------+---------------+--------------+------------------+\n\n");
	printf("| %-3s | %-25s | %-13s | %-12s | %-16s |\n", "STT", "Ho va ten", "Dia chi", "Ngay ung ho", "So tien");
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
	printf("| %-3d | %-25s | %-13s | %-12s | %-16.2f |\n", nguoiunghoitnhat->stt, nguoiunghoitnhat->ten, nguoiunghoitnhat->diachi,nguoiunghonhieunhat->ngayungho, nguoiunghoitnhat->sotien);
	printf("+-----+---------------------------+---------------+--------------+------------------+\n");
}