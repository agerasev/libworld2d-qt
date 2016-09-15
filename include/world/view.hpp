#pragma once

#include <QGraphicsView>
#include <QWheelEvent>

#include "scene.hpp"

#include <cstdio>


class View : public QGraphicsView {
public:
	float zf = 1.25;
	Scene &scene;
	
	View(Scene &s) : QGraphicsView(),
		scene(s)
	{
		setScene(&scene);
		
		setStyleSheet( "border-style: none;");

		setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

		setDragMode(ScrollHandDrag);
		setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
		// setAlignment(Qt::AlignCenter);
		
		setRenderHint(QPainter::Antialiasing);
	}

	virtual void enterEvent(QEvent *event) override {
		QGraphicsView::enterEvent(event);
		viewport()->setCursor(Qt::ArrowCursor);
	}
	
	virtual void mousePressEvent(QMouseEvent *event) override {
		QGraphicsView::mousePressEvent(event);
		viewport()->setCursor(Qt::ArrowCursor);
	}
	
	virtual void mouseReleaseEvent(QMouseEvent *event) override {
		QGraphicsView::mouseReleaseEvent(event);
		viewport()->setCursor(Qt::ArrowCursor);
	}
	
	virtual void mouseDoubleClickEvent(QMouseEvent *event) override {
		QGraphicsView::mouseDoubleClickEvent(event);
		centerOn(0, 0);
	}
	
	void fit() {
		auto t = transform();
		auto r = sceneRect();
		vec2 sv = vec2(t.m11()*r.width(), t.m22()*r.height());
		auto s = size();
		vec2 vv = vec2(s.width(), s.height());
		double z = min(0.9*vv/sv);
		if(z > 1.0) {
			scale(z, z);
		}
	}
	
	virtual void wheelEvent(QWheelEvent *event) override {
		// QGraphicsView::wheelEvent(event);
		double z = pow(zf, event->delta()/120.0);
		scale(z,z);
		fit();
	}
	
	virtual void resizeEvent(QResizeEvent *event) override {
		QGraphicsView::resizeEvent(event);
		fit();
	}
};
