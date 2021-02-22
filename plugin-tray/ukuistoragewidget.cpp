/*
 * Copyright (C) 2019 Tianjin KYLIN Information Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU  Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/&gt;.
 *
 */

#include "ukuistoragewidget.h"
//Qt
#include <QDebug>
//paint
#include <QPainter>
#include <QStyleOption>
#include <QPainterPath>
#include <QStyleOption>
#include <QStyle>
//layout
#include "../panel/common/ukuigridlayout.h"
//收纳栏目图标布局
UKUiStorageWidget::UKUiStorageWidget()
{
    setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明

}
void UKUiStorageWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    p.setBrush(QBrush(QColor(0x13,0x14,0x14,0x4d)));
    p.setPen(Qt::NoPen);
    p.setRenderHint(QPainter::Antialiasing);
    p.drawRoundedRect(opt.rect,6,6);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

#define mWinWidth 46
#define mWinHeight 46
void UKUiStorageWidget::setStorageWidgetButtonLayout(int size)
{
    int winWidth = 0;
    int winHeight = 0;

    this->setLayout(new UKUi::GridLayout);

    switch(size)
    {
    case 1:
        winWidth  = mWinWidth;
        winHeight = mWinHeight;
        this->setFixedSize(winWidth,winHeight);
        dynamic_cast<UKUi::GridLayout*>(this->layout())->setColumnCount(1);
        dynamic_cast<UKUi::GridLayout*>(this->layout())->setRowCount(1);
        break;
    case 2:
        winWidth  = mWinWidth*2;
        winHeight = mWinHeight;
        this->setFixedSize(winWidth,winHeight);
        dynamic_cast<UKUi::GridLayout*>(this->layout())->setColumnCount(2);
        dynamic_cast<UKUi::GridLayout*>(this->layout())->setRowCount(1);
        break;
    case 3:
        winWidth  = mWinWidth*3;
        winHeight = mWinHeight;
        this->setFixedSize(winWidth,winHeight);
        dynamic_cast<UKUi::GridLayout*>(this->layout())->setColumnCount(3);
        dynamic_cast<UKUi::GridLayout*>(this->layout())->setRowCount(1);
        break;
    case 4 ... 6:
        winWidth  = mWinWidth*3;
        winHeight = mWinHeight*2;
        this->setFixedSize(winWidth,winHeight);
        dynamic_cast<UKUi::GridLayout*>(this->layout())->setColumnCount(3);
        dynamic_cast<UKUi::GridLayout*>(this->layout())->setRowCount(2);
        break;
    case 7 ... 9:
        winWidth  = mWinWidth*3;
        winHeight = mWinHeight*3;
        this->setFixedSize(winWidth,winHeight);
        dynamic_cast<UKUi::GridLayout*>(this->layout())->setColumnCount(3);
        dynamic_cast<UKUi::GridLayout*>(this->layout())->setRowCount(3);
        break;
    case 10 ... 12:
        winWidth  = mWinWidth*3;
        winHeight = mWinHeight*4;
        this->setFixedSize(winWidth,winHeight);
        dynamic_cast<UKUi::GridLayout*>(this->layout())->setColumnCount(3);
        dynamic_cast<UKUi::GridLayout*>(this->layout())->setRowCount(4);
        break;
    case 13 ... 40:
        //默认情况下的布局
        winWidth  = mWinWidth*4;
        winHeight = mWinHeight*4;
        this->setFixedSize(winWidth,winHeight);
        dynamic_cast<UKUi::GridLayout*>(this->layout())->setColumnCount(4);
//        dynamic_cast<UKUi::GridLayout*>(this->layout())->setRowCount(7);
        break;
    default:
        //
        winWidth  = 0;
        winHeight = 0;
        this->setFixedSize(winWidth,winHeight);
        dynamic_cast<UKUi::GridLayout*>(this->layout())->setColumnCount(4);
//        dynamic_cast<UKUi::GridLayout*>(this->layout())->setRowCount(7);
        break;
    }
}
