#ifndef _TARGET_DETECTOR_H_
#define _TARGET_DETECTOR_H_

class RoundTarget
{
public:
	//检测靶标
	int Detect(Mat &img);

	//设置实际监测点的位置
	void SetMarkPos(Point2d ul, Point2d ur, Point2d dl, Point2d dr);

	//获取分值
	int GetScore(Point2d pt);

private:
	//检测到的靶标位置
	Point2d m_ul, m_ur, m_dl, m_dr;
};

#endif
