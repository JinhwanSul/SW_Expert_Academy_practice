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
  
  private:
    int row;
    int col;
    int x;
    int y;
};

int storage[100][100];
Chemical chems[20];
int chem_cnt;

bool check_already_in(int findr, int findc) {
    for(int i = 0; i < chem_cnt; i++) {
        if (chems[i].isInside(findr, findc)) {
            return true;
        }
    }
    return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

//	freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin>>N;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin>>storage[i][j];
            }
        }
        
        int findr, findc, chem_row, chem_col;
        chem_cnt = 0;

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
                        int k;
                        for(k = 0; k < chem_cnt; k++) {
                            if(chems[k] > chch) {
                                for(int l = chem_cnt-1; l >= k; l--) {
                                    chems[l+1] = chems[l];
                                }

                                chems[k] = chch;
                                break;
                            }
                        }
                        if(k == chem_cnt) {
                            chems[k] = chch;
                        }
                        chem_cnt++;
                    }
                }
            }
        }

        printf("#%d %d", test_case, chem_cnt);
        for(int i = 0; i < chem_cnt; i++) {
            chems[i].print_chem();
        }
        printf("\n");

	}
	return 0;
}