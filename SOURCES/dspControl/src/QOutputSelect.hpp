#ifndef QOUTPUTSELECT_HPP
#define QOUTPUTSELECT_HPP

#include <QWidget>
#include <QListView>

#include "QDspBlock.hpp"

#include "vektorraum.h"

#include "freeDSP-Aurora.hpp"

namespace Ui {
class QOutputSelect;
}

class QOutputSelect : public QDspBlock
{
  Q_OBJECT

  enum
  {
    kOutput = 0,
    kNumParams
  };

public:
  explicit QOutputSelect( uint32_t selection, uint16_t outputaddr, CFreeDspAurora* ptrdsp, QWidget *parent = nullptr );
  ~QOutputSelect();

  virtual Vektorraum::tvector<Vektorraum::tcomplex> getTransferFunction( void )
  {
    return H;
  }

  void update( Vektorraum::tvector<Vektorraum::tfloat> f );

  virtual void getUserParams( QByteArray* userParams );

  virtual void setUserParams( QByteArray& userParams, int& idx );

  virtual void sendDspParameter( void );

  virtual uint32_t getNumBytes( void );

  //virtual void writeDspParameter( void );

  virtual QByteArray getDspParams( void );

  bool eventFilter( QObject* object, QEvent* event );

private slots:
  //void on_comboBoxInput_currentIndexChanged( int  );

private:
  Ui::QOutputSelect *ui;

  uint16_t addr[kNumParams];
  CFreeDspAurora* dsp;
  QString fileName;

  Vektorraum::tvector<Vektorraum::tfloat> freq;
  Vektorraum::tvector<Vektorraum::tcomplex> FR;
  Vektorraum::tfloat refSpl;
};

#endif // QOUTPUTSELECT_HPP
