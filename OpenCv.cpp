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

// Trabalho 1 — Filtros Espaciais e Nitidez 

// 1. Fácil — Negativo fotográfico. Inverter a intensidade de cada canal, limitando os 
// resultados ao intervalo válido. 

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
}
// 2. Intermédio — Filtro de média.Implementar uma convolução com janela quadrada 
// e permitir alterar o tamanho da janela.

		using namespace cv;
		using namespace std;

		int main(int, char**) {
			Mat image;


			image = imread("Lena.png");

			if (!image.data)
				cout << "nao abriu Lena.png" << endl;

			Mat invertida;

			blur(image, invertida, Size(15, 15));

			subtract(image, invertida, Size(15, 15));


			imshow("lena2.png", invertida);
			imshow("janela", invertida);
			waitKey();
			return 0;
		}

		
	// 3. Intermédio — Filtro Gaussiano. Construir o núcleo Gaussiano a partir do tamanho
	// da janela e do desvio - padrão e aplicá - lo por convolução.

		/*
	Mat gauss;

	Mat suave;
	GaussianBlur(img, suave, Size(5, 5), 1.2);

	imshow("Gaussiano", gauss);

	*/

// 4. Difícil — Máscara de nitidez(unsharp masking).Suavizar a imagem, calcular
// a diferença para a original e reforçar os detalhes com um factor configurável.



// 5. Difícil — Realce por Laplaciano.Implementar o operador Laplaciano e combiná - lo
// com a imagem original para realçar transições de intensidade.



