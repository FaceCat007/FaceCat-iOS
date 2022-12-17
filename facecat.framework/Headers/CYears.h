/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __CYEARS_H__
#define __CYEARS_H__
#pragma once
#include "stdafx.h"
#include "CYear.h"

namespace FaceCat{
    /*
     * 年的集合
     */
    class CYears{
    public:
        /**
         * 日历
         */
        CYears();
        virtual ~CYears();
        /**
         * 年的集合
         */
        HashMap<Integer,CYear*> Years;
        /**
         * 获取年
         * @param  year 年份
         */
        CYear* getYear(int year);
    };
}

#endif
