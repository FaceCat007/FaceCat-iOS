/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */
#ifndef __MONTHDIV_H__
#define __MONTHDIV_H__
#pragma once
#include "stdafx.h"
#include "MonthButton.h"
#include "HeadDiv.h"
#include "TimeDiv.h"
#include "FCCalendar.h"

namespace FaceCat{
    class MonthButton;
    class HeadDiv;
    class FCCalendar;
    class TimeDiv;
    
    /*
     * 月的层
     */
    class MonthDiv{
    public:
        /**
         * 动画的方向
         */
        int m_am_Direction;
        /**
         * 动画当前帧数
         */
        int m_am_Tick;
        /**
         * 动画总帧数
         */
        int m_am_TotalTick;
        /**
         * 日历控件
         */
        FCCalendar *m_calendar;
        /**
         * 年份
         */
        int m_year;
    public:
        /**
         * 月的按钮
         */
        ArrayList<MonthButton*> m_monthButtons;
        /**
         * 月的动画按钮
         */
        ArrayList<MonthButton*> m_monthButtons_am;
    public:
        /*
         * 构造函数
         */
        MonthDiv(FCCalendar *calendar);
        /*
         * 析构函数
         */
        virtual ~MonthDiv();
        /**
         * 获取日历控件
         */
        virtual FCCalendar* getCalendar();
        /**
         * 设置日历控件
         */
        virtual void setCalendar(FCCalendar *value);
        /**
         * 获取年份
         */
        virtual int getYear();
    public:
        /**
         * 隐藏
         */
        virtual void hide();
        /**
         * 触摸点击方法
         * @param  touchInfo   触摸信息
         */
        virtual void onClick(FCTouchInfo touchInfo);
        /**
         * 添加控件方法
         */
        virtual void onLoad();
        /**
         * 重绘方法
         * @param  paint   绘图对象
         * @param  clipRect   裁剪区域
         */
        virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
        /**
         * 重置日期图层
         * @param  state   状态
         */
        virtual void onResetDiv(int state);
        /**
         * 秒表触发方法
         */
        virtual void onTimer();
        /**
         * 选择年份
         * @param  year   年份
         */
        virtual void selectYear(int year);
        /**
         * 显示
         */
        virtual void show();
        /**
         * 更新布局方法
         */
        void update();
    };
}
#endif
