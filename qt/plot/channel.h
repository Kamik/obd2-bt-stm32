#ifndef CHANNEL_H
#define CHANNEL_H

#include <QWidget>
#include <QVector>

namespace Ui
{
	class channel;
}

enum e_type
{
	e_type_byte = 0,
	e_type_word_le,
	e_type_word_be,

};

struct qid_t
{
	uint32_t id;
	QString name;
};

class channel_t : public QWidget
{
	Q_OBJECT

	private:
		uint32_t idx;
		Ui::channel * ui;

	private slots:
		void slt_activated();
		void slt_change_id();

	public slots:
		void slt_btn_en(bool en);
		void slt_btn_swap(bool en);
		void slt_set_id(uint32_t idx);

	public:
		channel_t(uint32_t idx, QWidget *parent = 0);
		~channel_t();
		void set_ids(QVector <qid_t>);
		void set_group(bool en);

	signals:
		void sig_enabled(int idx, uint32_t id, int type, int off, uint16_t mask, double mul, double add, bool swap);
		void sig_disabled(int idx);
		void sig_change_id(int idx);
};

#endif

