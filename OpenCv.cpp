//OpenCv.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali. 
// 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <Math.h> 
#include <opencv2/opencv.hpp> 
#include <opencv2/core.hpp> 
#include <opencv2/imgcodecs.hpp> 
#include <opencv2/highgui.hpp> 
#include <opencv2/imgproc.hpp> 
#include <algorithm> 
#include <iostream>
#include <cmath>
#include <vector>

// Trabalho 1 — Filtros Espaciais e Nitidez 

// 1. Fácil — Negativo fotográfico. Inverter a intensidade de cada canal, limitando os 
// resultados ao intervalo válido. 
/*

using namespace cv;
using namespace std;

int main(int, char**) {
	Mat image;


	image = imread("Lena.png");

	if (!image.data)
		cout << "nao abriu Lena.png" << endl;

	Mat invertida = image.clone();

	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {
			for (int c = 0; c < 3; c++) {


				invertida.at<Vec3b>(i, j)[c] = 255 - image.at<Vec3b>(i, j)[c];
			}
		}
	}


	imwrite("lena2.png", image);
	imshow("janela", invertida);
	waitKey();
	return 0;
}*/
// 2. Intermédio — Filtro de média.Implementar uma convolução com janela quadrada 
// e permitir alterar o tamanho da janela.

using namespace cv;
using namespace std;

Mat image;
int tamanhoslider = 1;
const int maxSlider = 30;
void aoMudarSlider(int, void*) {
	int ksize = tamanhoslider * 2 + 1;

	Mat resultado;
	blur(image, resultado, Size(ksize, ksize));

	imshow("Imagem", resultado);
}

int main(int, char**) {
	image = imread("Lena.png");

	if (image.empty()) {
		cout << "Nao abriu Lena.png" << endl;
		return -1;
	}

	namedWindow("Imagem", WINDOW_AUTOSIZE);

	
	aoMudarSlider(0, 0);

	waitKey(0);
	return 0;
}

*/		
	// 3. Intermédio — Filtro Gaussiano. Construir o núcleo Gaussiano a partir do tamanho
	// da janela e do desvio - padrão e aplicá - lo por convolução.

using namespace cv;
using namespace std;

int main(int, char**) {
    Mat image = imread("Lena.png");

    if (image.empty()) {
        cout << "Nao abriu Lena.png" << endl;
        return -1;
    }

    int tamanhoJanela = 9;
    double sigma = 2.0;
    int raio = tamanhoJanela / 2;

    vector<vector<double>> kernel(tamanhoJanela, vector<double>(tamanhoJanela));
    double somaPesos = 0.0;

    for (int y = -raio; y <= raio; y++) {
        for (int x = -raio; x <= raio; x++) {
            double peso = exp(-(x * x + y * y) / (2.0 * sigma * sigma));
            kernel[y + raio][x + raio] = peso;
            somaPesos += peso;
        }
    }

    Mat resultado = image.clone();

    for (int i = raio; i < image.rows - raio; i++) {
        for (int j = raio; j < image.cols - raio; j++) {
            double somaB = 0, somaG = 0, somaR = 0;

            for (int dy = -raio; dy <= raio; dy++) {
                for (int dx = -raio; dx <= raio; dx++) {
                    Vec3b pixel = image.at<Vec3b>(i + dy, j + dx);
                    double peso = kernel[dy + raio][dx + raio];

                    somaB += pixel[0] * peso;
                    somaG += pixel[1] * peso;
                    somaR += pixel[2] * peso;
                }
            }

            resultado.at<Vec3b>(i, j)[0] = somaB / somaPesos;
            resultado.at<Vec3b>(i, j)[1] = somaG / somaPesos;
            resultado.at<Vec3b>(i, j)[2] = somaR / somaPesos;
        }
    }

    imshow("Filtro Gaussiano", resultado);
    waitKey(0);
    return 0;
}

// 4. Difícil — Máscara de nitidez(unsharp masking).Suavizar a imagem, calcular
// a diferença para a original e reforçar os detalhes com um factor configurável.



// 5. Difícil — Realce por Laplaciano.Implementar o operador Laplaciano e combiná - lo
// com a imagem original para realçar transições de intensidade.



