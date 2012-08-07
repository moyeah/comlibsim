#ifndef __H_POSITION__
#define __H_POSITION__

namespace ComLibSim
{

class Position: public Object
{
private:
  double m_x;
  double m_y;

public:
  Position ();
  Position (double x, double y);
  Position (const Position& position);
  virtual ~Position ();

  virtual Object*   object     () const;
  virtual void      copy       (const Position& position);
  virtual Position& operator = (const Position& position);

  virtual bool operator == (const Position& position) const;
  virtual bool operator != (const Position& position) const;

  virtual double get_x () const;
  virtual double get_y () const;
  
  virtual double distance_to (const Position& position) const;

  virtual void write    (std::ostream& output = std::cout) const;
  virtual void write_ln (std::ostream& output = std::cout) const;

  friend std::ostream& operator << (std::ostream& output,
                                    const Position& position);
};

}

#endif
