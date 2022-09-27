#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>
#include <iterator>
#include <map>
#include <string>
#include <chrono>


using namespace std;


int test_sayisi;
int dogruluk_orani;

void yuzdeHesapla(string tahminiSonuc, string gercekSonuc ){
    
    //Dosyadan değerleri okuma
    std::vector<int> newVector;
    ifstream input_file( "Test sonuclarinin okunacagi yeri girin"  );
    int tempVar;

    while ( input_file >> tempVar )
    {
        newVector.push_back( tempVar );
    }
    test_sayisi = newVector.at(0);
    dogruluk_orani = newVector.at(1);



    test_sayisi++;

    if(tahminiSonuc == gercekSonuc){
        dogruluk_orani++;
    }

    float dogruluk_yuzdesi = (float(dogruluk_orani) / float(test_sayisi)) * 100 ;

    cout << "KNN Doğruluk Yüzdesi : %" << dogruluk_yuzdesi << endl;
    
    //Dosyaya değerleri yazma
    std::vector<int> b = {test_sayisi,dogruluk_orani};
    ofstream output_file( "Test sonuclarinin aktarilacagi yeri girin" );
    ostream_iterator<int> output_iterator( output_file, "\n" );
    copy( b.begin( ), b.end( ), output_iterator );

}

int main()
{

    auto start = chrono::steady_clock::now();


    map<float,std::string > trainset;


    //Iris Dataseti
    float iris_data[120][4] =  {   {5.1,3.5,1.4,0.2},
                                {4.9,3.0,1.4,0.2},
                                {4.7,3.2,1.3,0.2},
                                {4.6,3.1,1.5,0.2},
                                {5.0,3.6,1.4,0.2},
                                {5.4,3.9,1.7,0.4},
                                {4.6,3.4,1.4,0.3},
                                {5.0,3.4,1.5,0.2},
                                {4.4,2.9,1.4,0.2},
                                {4.9,3.1,1.5,0.1},
                                {5.4,3.7,1.5,0.2},
                                {4.8,3.4,1.6,0.2},
                                {4.8,3.0,1.4,0.1},
                                {4.3,3.0,1.1,0.1},
                                {5.8,4.0,1.2,0.2},
                                {5.7,4.4,1.5,0.4},
                                {5.4,3.9,1.3,0.4},
                                {5.1,3.5,1.4,0.3},
                                {5.7,3.8,1.7,0.3},
                                {5.1,3.8,1.5,0.3},
                                {5.4,3.4,1.7,0.2},
                                {5.1,3.7,1.5,0.4},
                                {4.6,3.6,1.0,0.2},
                                {5.1,3.3,1.7,0.5},
                                {4.8,3.4,1.9,0.2},
                                {5.0,3.0,1.6,0.2},
                                {5.0,3.4,1.6,0.4},
                                {5.2,3.5,1.5,0.2},
                                {5.2,3.4,1.4,0.2},
                                {4.7,3.2,1.6,0.2},
                                {4.8,3.1,1.6,0.2},
                                {5.4,3.4,1.5,0.4},
                                {5.2,4.1,1.5,0.1},
                                {5.5,4.2,1.4,0.2},
                                {4.9,3.1,1.5,0.1},
                                {5.0,3.2,1.2,0.2},
                                {5.5,3.5,1.3,0.2},
                                {4.9,3.1,1.5,0.1},
                                {4.4,3.0,1.3,0.2},
                                {5.1,3.4,1.5,0.2},
                                {7.0,3.2,4.7,1.4},
                                {6.4,3.2,4.5,1.5},
                                {6.9,3.1,4.9,1.5},
                                {5.5,2.3,4.0,1.3},
                                {6.5,2.8,4.6,1.5},
                                {5.7,2.8,4.5,1.3},
                                {6.3,3.3,4.7,1.6},
                                {4.9,2.4,3.3,1.0},
                                {6.6,2.9,4.6,1.3},
                                {5.2,2.7,3.9,1.4},
                                {5.0,2.0,3.5,1.0},
                                {5.9,3.0,4.2,1.5},
                                {6.0,2.2,4.0,1.0},
                                {6.1,2.9,4.7,1.4},
                                {5.6,2.9,3.6,1.3},
                                {6.7,3.1,4.4,1.4},
                                {5.6,3.0,4.5,1.5},
                                {5.8,2.7,4.1,1.0},
                                {6.2,2.2,4.5,1.5},
                                {5.6,2.5,3.9,1.1},
                                {5.9,3.2,4.8,1.8},
                                {6.1,2.8,4.0,1.3},
                                {6.3,2.5,4.9,1.5},
                                {6.1,2.8,4.7,1.2},
                                {6.4,2.9,4.3,1.3},
                                {6.6,3.0,4.4,1.4},
                                {6.8,2.8,4.8,1.4},
                                {6.7,3.0,5.0,1.7},
                                {6.0,2.9,4.5,1.5},
                                {5.7,2.6,3.5,1.0},
                                {5.5,2.4,3.8,1.1},
                                {5.5,2.4,3.7,1.0},
                                {5.8,2.7,3.9,1.2},
                                {6.0,2.7,5.1,1.6},
                                {5.4,3.0,4.5,1.5},
                                {6.0,3.4,4.5,1.6},
                                {6.7,3.1,4.7,1.5},
                                {6.3,2.3,4.4,1.3},
                                {5.6,3.0,4.1,1.3},
                                {5.5,2.5,4.0,1.3},
                                {6.3,3.3,6.0,2.5},
                                {5.8,2.7,5.1,1.9},
                                {7.1,3.0,5.9,2.1},
                                {6.3,2.9,5.6,1.8},
                                {6.5,3.0,5.8,2.2},
                                {7.6,3.0,6.6,2.1},
                                {4.9,2.5,4.5,1.7},
                                {7.3,2.9,6.3,1.8},
                                {6.7,2.5,5.8,1.8},
                                {7.2,3.6,6.1,2.5},
                                {6.5,3.2,5.1,2.0},
                                {6.4,2.7,5.3,1.9},
                                {6.8,3.0,5.5,2.1},
                                {5.7,2.5,5.0,2.0},
                                {5.8,2.8,5.1,2.4},
                                {6.4,3.2,5.3,2.3},
                                {6.5,3.0,5.5,1.8},
                                {7.7,3.8,6.7,2.2},
                                {7.7,2.6,6.9,2.3},
                                {6.0,2.2,5.0,1.5},
                                {6.9,3.2,5.7,2.3},
                                {5.6,2.8,4.9,2.0},
                                {7.7,2.8,6.7,2.0},
                                {6.3,2.7,4.9,1.8},
                                {6.7,3.3,5.7,2.1},
                                {7.2,3.2,6.0,1.8},
                                {6.2,2.8,4.8,1.8},
                                {6.1,3.0,4.9,1.8},
                                {6.4,2.8,5.6,2.1},
                                {7.2,3.0,5.8,1.6},
                                {7.4,2.8,6.1,1.9},
                                {7.9,3.8,6.4,2.0},
                                {6.4,2.8,5.6,2.2},
                                {6.3,2.8,5.1,1.5},
                                {6.1,2.6,5.6,1.4},
                                {7.7,3.0,6.1,2.3},
                                {6.3,3.4,5.6,2.4},
                                {6.4,3.1,5.5,1.8},
                                {6.0,3.0,4.8,1.8},
                                {6.9,3.1,5.4,2.1},

    };
    //Iris Verileri
    string iris_result[120] = {

            "Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa",
            "Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa",
            "Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa",
            "Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa","Iris-setosa",
            "Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor",
            "Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor",
            "Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor",
            "Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor","Iris-versicolor",
            "Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica",
            "Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica",
            "Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica",
            "Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica","Iris-virginica"
    };

    //Test edilecek data
    float test_data[] = {7.1,4.0,5.6,2.4};
    string test_name = "Iris-versicolor";
   

    //Datasetindeki verilerle karşılaştırıp öklidini bulma
    for(int i = 0; i< 120; i++){
        
        float oklid = 0.00;
        for(int j = 0; j<=3; j++){
            oklid += pow((test_data[j] - iris_data[i][j]),2);
        }
        oklid = sqrt(oklid);
        
            trainset.insert(pair<float,string>(oklid,iris_result[i]));
        
        
    }

    int count_virginica = 0;
    int count_setosa = 0;
    int count_versicolor= 0;
    int counter = 1;
    int k_neighbour = 1;
    int virginica = 0;
    int setosa = 0;
    int versicolor = 0;
    
    for(auto it = trainset.begin(); it != trainset.end(); ++it){

        cout << counter << ". veri : " << it -> first << " = " << it -> second << endl;

        if(k_neighbour <= 5){
            if((it -> second) == "Iris-virginica"){
                virginica++;
            }
            else if((it -> second) == "Iris-setosa"){
                setosa++;
            }else{
                versicolor++;
            }
        }

        if((it -> second) == "Iris-virginica"){
            count_virginica++;
        }
        else if((it -> second) == "Iris-setosa"){
            count_setosa++;
        }else{
            count_versicolor++;
        }
        counter++;
        k_neighbour++;

    }
    //Map'i temizleme
    trainset.clear();
    
    //Etiketlerin gruplara göre sayılarının belirlenmesi
    cout << "Virginica = " << count_virginica << endl;
    cout << "Seposa = " << count_setosa << endl;
    cout << "Versicolor= " << count_versicolor << endl;

    string beklenenSonuc;

    if(virginica > setosa){
        if(virginica> versicolor){
            beklenenSonuc = "Iris-virginica";
            cout << "Beklenenen sonuç : " << beklenenSonuc << endl;
        }else{
            beklenenSonuc = "Iris-versicolor";
            cout << "Beklenenen sonuç : " << beklenenSonuc << endl;
        }
    }else{
        if(setosa > versicolor){
            beklenenSonuc = "Iris-setosa";
            cout << "Beklenenen sonuç : " + beklenenSonuc;
        }else{
            beklenenSonuc = "Iris-versicolor";
            cout << "Beklenenen sonuç : " << beklenenSonuc << endl;
    }
        }

    cout << "Gerçek sonuç : " << test_name << endl;

    yuzdeHesapla(beklenenSonuc,test_name);


    auto end = chrono::steady_clock::now();

    //Süre-ölçerler
    cout << "Elapsed time in nanoseconds: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << " ns" << endl;

    cout << "Elapsed time in microseconds: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " µs" << endl;

    cout << "Elapsed time in milliseconds: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;

    cout << "Elapsed time in seconds: "
         << chrono::duration_cast<chrono::seconds>(end - start).count()
         << " sec\n";

    return 0;
}


