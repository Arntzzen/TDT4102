#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <sstream>

// Kode for å generere ca 1 GB med tull.
// Format: "geigvoerv,kfewbqb,frbewirfi,rnview,fniwe,nawc,nfierv,fewffw".

const size_t TARGET_SIZE = 1024ULL * 1024 * 1024;
const int MIN_WORD_LENGTH = 5;
const int MAX_WORD_LENGTH = 25;
const int WORDS_PER_LINE = 8;


const std::vector<std::string> SECRET_ARRAY = {
    "YVPPFLKYZJNRJ", "RMVIPXFFU", "ZUVRREU", "PFLRIVHLZKV", "TCVMVIREU", "ZDLJK", "RGGCRLUTIVRKZMV", "ZUVRJYFNVMVIZ",
    "RDFEVJKVG", "RYVRUREUJFZ", "YRMVRJLIGIZJV", "WFIPFLGCVRJVUFVEAFP", "KYVWFCCFNZEXVOTVIGK", "WIFDRNFEUVIWLCSFFBZ",
    "VEAFP", "ZDGRKZVEKCP", "EVZXYSFLIYFFU", "FIFKYVI", "DPUVRIDISVEEVKJRZUYZJ", "JZEXCVDRE", "WFIKLEV", "KFKVCCDVREU",
    "DLJKSVZENREKFWR", "ZYRMVEF", "ZJKFKRBVGFJJJVJJZFE", "EFIKYFW", "WFLIKFJVV", "KYVPRCCKYZEB", "ZDDVUZRKVCPKYRKYV",
    "GFZEKVIJ", "FWKYVZI", "RIVEVRKKYVPRIV", "JZDGCP", "JYVKFCUDVRCCRSFLKZK", "KYRKYVRXIVVUNZKYDIDFIIZJJ",
    "DLJKBEFNDIJCFEX", "KYZJNRJ", "ALJKSVVEYVIVREU", "BEFNNYF", "UVCZXYKVUNZKYZK", "KYZJKILKYZJ", "KFEZTV",
    "YZJJVIMREKJ", "ZEMZKRKZFEVEFLXYNYP", "ZEGFJJVJJZFEFWR", "RIVKFSVZE", "RTBEFNCVUXVUKYRKR", "SVEEVKIVGCZVU",
    "KFSVRK", "WRDZCZVJKYRKYVZJTFEJZUVIVURJKYV", "BEFNCVUXVYRJ", "TRDVUFNEFEDFEURPZER", "XIFNVU", "CZKKCVBEFNE",
    "GRIBZJCVK", "JRPJKYRKEVKYVIWZVCU", "WFIDIJCFEXYRJ", "FSAVTKZFE", "NZWVYFNVMVI", "XFFUWFIKLEV", "RPFLEXDRE",
    "EVKYVIWZVCU", "TYRZJVREU", "YRJKRBVEZKTIZVU", "ZJKRBVESP", "KYVDZEUJFWKYV", "KYVGCRTVREU", "FEVURPYRMVPFL",
    "FWJLTYR", "DISVEEVKDRUVEFREJNVIUFEFK", "EFSLXJ", "KYVWVVCZEXJ", "KYVYFLJVSPKYV", "FIMZVNJ", "REUJFDVFW",
    "KYRKYVYRU", "NRJJFDLTY", "RKCRJKDDI", "WIFDKYV", "PFLNREKKF", "WZIJJKVEKVIZEXR", "URLXYKVIJ", "FWCRIXV",
    "SVWFIVDZTYRVCJDRJ", "YZJNZWV", "VEXCREUKYRKYV", "WZOVUZE", "IZXYKWLCGIFGVIKPFWJFDVFEV", "CRUPKFYZD", "ZEDPTFUV",
    "ZKZJRKILKYLEZMVIJRCCP", "JLIIFLEUZEX", "KFYVRIZEXZK", "JFNVCCC", "PFLNREK", "KYVKRJKVFW", "DREDRPSVFEYZJ",
    "YVRIUKYRK", "VEUFWEVOKNVVB", "DPUVRIPFL", "CVRIEZEXJJFJNVVK", "EFKSLKZKZJIVKLIEVUJYV"
};


// generer oddetallsord
std::string generateWords(int length) {
    std::string word;
    for (int i = 0; i < length; ++i) {
        char letter = 'A'+rand()%26;
        word += letter;
    }
    
    if (word.length() % 2 == 0) {
        word.pop_back();
    }
    return word;
}

std::string generateLine(int lineNmbr) {
    std::stringstream line;
    static int secretWord = 0;
    for (int i = 0; i < WORDS_PER_LINE; ++i) {
        std::string word;

        bool canAddSecret = (lineNmbr % 2 ==1);
        if (i == WORDS_PER_LINE -1 && secretWord < SECRET_ARRAY.size() && canAddSecret) {
            word = SECRET_ARRAY[secretWord++];
        } else{
            int len = MIN_WORD_LENGTH + rand() % (MAX_WORD_LENGTH - MIN_WORD_LENGTH + 1);
            word = generateWords(len);
        }
        
        line << word;
        if (i < WORDS_PER_LINE -1) {
            line << ",";
        }
    }
    return line.str();
}


int main() {
    std::ofstream file("cipher.csv");
    if (!file.is_open()) {
        std::cerr << "Kunne ikke åpne filen. \n";
        return 1;
    }
    srand(static_cast<unsigned>(time(nullptr)));
    size_t currentSize = file.tellp();

    int i;
    while (currentSize < TARGET_SIZE) {
        static int lineNmbr = 1;
        std::string line = generateLine(lineNmbr++);
        file << line << "\n";
        if (file.fail()) {
            std::cerr << "Problem dersom filen blir så stor at os spinner vilt. \n";
            break;
        }
        currentSize = file.tellp();
        std::cout << "\rGenerating CSV.. ";
        std::cout << std::flush;
    }

    std::cout << std::endl;
    std::cout << "CSV fil generert. \n";
    return 0;
}



