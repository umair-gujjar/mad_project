#include <iostream>
#include <cv.h>
#include <highgui.h>
using namespace std;
using namespace cv;

int main(){
	int l,b, cx,cy;
	l = 640;	b = 640;
	//cout<<"Enter the length and breadth, seperated by a space:"<<endl;
	//cin>>l; cin>>b;

//	cout<<"Enter the coordinates of camera:"<<endl<<"Fomat: x y "<<endl;
	//cin>>cx;	cin>>cy;

	Mat img = Mat(l,b,CV_32FC1, Scalar(100000));
	Mat frame1,frame2;
	//Mat Dframe=Mat(l,b,CV_32FC3, Scalar(300,400,500));
	Mat Dframe1, Dframe2, df3,df4;
	VideoCapture cap(0);

	namedWindow("Video"); namedWindow("DVideo"); namedWindow("Image"); namedWindow("DV2");

	imshow("Image",img);

	cap>>frame1; 	cap>>frame2;
	cvtColor(frame1,frame1, CV_RGB2GRAY);
	cvtColor(frame2,frame2, CV_RGB2GRAY);
	Dframe1 = frame2-frame1;

	//cvtColor(Dframe1, Dframe1, CV_GRAY2RGB);
	inRange(Dframe1, Scalar(50), Scalar(200),df4);

	imshow("Video",frame1); 	imshow("DVideo",Dframe1);
	//cout<<Dframe<<endl;
	int r,c, rd,cd;
	while(char(waitKey(1))!='q'){
		frame1 = frame2;
		cap>>frame2;
		cvtColor(frame2,frame2, CV_RGB2GRAY);
		Dframe1 = (frame2-frame1);
		//cvtColor(Dframe1, Dframe2, CV_GRAY2RGB);

		imshow("Video",frame1);
		imshow("DVideo",Dframe1);
		inRange(Dframe1, Scalar(50), Scalar(200),df3);
		df4+=df3;

/*		for(r=0; r<df3.rows; r++){
			for(c = 0; c < df3.cols; c++){

			}
		}*/
		imshow("DV2",df3);
		}
	return 0;
}

