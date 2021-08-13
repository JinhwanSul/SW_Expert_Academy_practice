#include<iostream>

using namespace std;

class Chemical {
  public:
    Chemical() {}
    Chemical(int r, int c, int x, int y) : row(r), col(c), x(x), y(y) {}

    bool isInside(int findr, int findc) {
        if((this->x <= findr && findr < this->x + this->row) && (this->y <= findc && findc < this->y + this->col)) {
            return true;
        }
        return false;
    }

    bool operator > (Chemical& chem) {
        if(this->row * this-> col > chem.row * chem.col) {
            return true;
        } else if (this->row * this-> col == chem.row * chem.col && this->row > chem.row) {
            return true;
        } else {
            return false;
        }
    }

    void print_chem(void) {
        printf(" %d %d", this->row, this->col);
    }
  
    int get_row(void) {
        return this->row;
    }

    int get_col(void) {
        return this->col;
    }

  private:
    int row;
    int col;
    int x;
    int y;
};

int storage[100][100];
Chemical chems[20];
Chemical chems_mat[20];
bool united[20];
int mat_row;
int mat_col;
int chem_cnt;
int ch_mat_cnt;

void inititate(void)
{
    ch_mat_cnt = 0;
    chem_cnt = 0;
    for(int i = 0; i < 20; i++) {
        united[i] = false;
    }
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            storage[i][j] = 0;
        }
    }
}

bool check_already_in(int findr, int findc) {
    for(int i = 0; i < chem_cnt; i++) {
        if (chems[i].isInside(findr, findc)) {
            return true;
        }
    }
    return false;
}

bool connect_mat(Chemical &new_ch)
{
    if(new_ch.get_col() == mat_row) {
        for(int i = ch_mat_cnt-1; i >= 0; i--) {
            chems_mat[i+1] = chems_mat[i];
        }
        chems_mat[0] = new_ch;
        mat_row = new_ch.get_row();
        ch_mat_cnt++;
        return true;
    } else if (new_ch.get_row() == mat_col) {
        chems_mat[ch_mat_cnt] = new_ch;
        mat_col = new_ch.get_col();
        ch_mat_cnt++;
        return true;
    }
    return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin>>N;
        inititate();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin>>storage[i][j];
            }
        }
        
        int findr, findc, chem_row, chem_col;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(storage[i][j] != 0 ) {
                    findr = i;
                    findc = j;
                    chem_row = 0;
                    chem_col = 0;
                    if(!check_already_in(findr, findc)){
                        while(storage[findr][j] != 0) {
                            findr++;
                            chem_row++;
                        }
                        while(storage[i][findc] != 0) {
                            findc++;
                            chem_col++;
                        }
                        Chemical chch(chem_row, chem_col, i, j);
                        chems[chem_cnt] = chch;
                        chem_cnt++;
                    }
                }
            }
        }

        mat_col = chems[0].get_col();
        mat_row = chems[0].get_row();
        chems_mat[0] = chems[0];
        ch_mat_cnt++;
        united[0] = 1;       
        
        // printf("[DEBUG] chem_cnt = %d\n", chem_cnt);
        // for(int i = 0; i < chem_cnt; i++) {
        //     chems[i].print_chem();
        //     printf("\n");
        // }
        for(int i = 1; i < chem_cnt; i++) {
            for(int j = 1; j < chem_cnt; j++) {
                if(united[j] == 0 && connect_mat(chems[j])) {
                    united[j] = 1;
                    break;
                }
            }
        }
        // printf("[DEBUG] #%d", test_case);
        // for(int i = 0; i < chem_cnt; i++) {
        //     chems_mat[i].print_chem();
        // }
        // printf("\n");

        // Matrix chain multiplication algorithm
        int min_k;
        int dynamic_table[20][20] = {0, };
        for(int r = 1; r < chem_cnt; r++) {
            for(int i = 0; i < chem_cnt-r; i++) {
                int j = i + r;
                dynamic_table[i][j] = INT32_MAX;
                for(int k = i; k < j; k++) {
                    min_k = dynamic_table[i][k] + dynamic_table[k+1][j] 
                            + chems_mat[i].get_row() * chems_mat[k].get_col() * chems_mat[j].get_col();
                    if(min_k < dynamic_table[i][j]) {
                        dynamic_table[i][j] = min_k;
                    }
                } 
            }
        }
        printf("#%d %d\n", test_case, dynamic_table[0][chem_cnt-1]);
	}
	return 0;
}