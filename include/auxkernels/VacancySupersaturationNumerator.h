/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef VacancySupersaturationNumeratorNUMERATOR_H
#define VacancySupersaturationNumeratorNUMERATOR_H

#include "AuxKernel.h"

//Forward Declarations
class VacancySupersaturationNumerator;

/**
 * validParams returns the parameters that this Kernel accepts / needs
 * The actual body of the function MUST be in the .C file.
 */
template<>
InputParameters validParams<VacancySupersaturationNumerator>();

class VacancySupersaturationNumerator : public AuxKernel
{
public:

  VacancySupersaturationNumerator(const InputParameters & parameters);

protected:
  virtual Real computeValue();

  /**
   * This MooseArray will hold the reference we need to our
   * material property from the Material class
   */

  VariableValue & _vacancies;
  VariableValue & _interstitials;
  VariableValue & _thermal_vacancies;
  const MaterialProperty<Real> & _D_v;
  const MaterialProperty<Real> & _D_i;

};
#endif //VacancySupersaturationNumeratorNUMERATOR_H
