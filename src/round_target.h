#ifndef _TARGET_DETECTOR_H_
#define _TARGET_DETECTOR_H_

class RoundTarget
{
public:
	//���б�
	int Detect(Mat &img);

	//����ʵ�ʼ����λ��
	void SetMarkPos(Point2d ul, Point2d ur, Point2d dl, Point2d dr);

	//��ȡ��ֵ
	int GetScore(Point2d pt);

private:
	//��⵽�İб�λ��
	Point2d m_ul, m_ur, m_dl, m_dr;
};

#endif
