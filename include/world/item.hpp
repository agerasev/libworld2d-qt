#pragma once

#include <QGraphicsItem>
#include <QPainter>

#include <la/vec.hpp>

#include <world/entity.hpp>


QPointF v2q(const vec2 &v) {
	return QPointF(v.x(), v.y());
}

QColor qmix(const QColor &a, const QColor &b, double r = 0.5) {
	return QColor(
		a.red()*r + b.red()*(1 - r),
		a.green()*r + b.green()*(1 - r),
		a.blue()*r + b.blue()*(1 - r),
		255
	);
}


class Item : public QGraphicsItem {
public:
	bool exists = true;
	double size;
	QColor color;
	
	Item() : QGraphicsItem() {
		color = QColor("#888888");
	}
	virtual ~Item() = default;
	
	virtual QRectF boundingRect() const override {
		return QRectF(-size, -size, 2*size, 2*size);
	}
	
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override {
		if(size > 0.0) {
			painter->setPen(Qt::NoPen);
			painter->setBrush(color);
			painter->drawEllipse(boundingRect());
		}
	}
	
	virtual void sync(const Entity *e) {
		setPos(v2q(e->pos));
		size = e->size();
		// update();
	}
};
