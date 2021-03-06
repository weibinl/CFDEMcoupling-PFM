/*---------------------------------------------------------------------------*\
    CFDEMcoupling academic - Open Source CFD-DEM coupling
    
    Contributing authors:
    Thomas Lichtenegger
    Copyright (C) 2015- Johannes Kepler University, Linz
-------------------------------------------------------------------------------
License
    This file is part of CFDEMcoupling academic.

    CFDEMcoupling academic is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    CFDEMcoupling academic is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with CFDEMcoupling academic.  If not, see <http://www.gnu.org/licenses/>.
\*---------------------------------------------------------------------------*/

#ifndef evaluateFluctuations_H
#define evaluateFluctuations_H

#include "forceModel.H"
#include "interpolationCellPoint.H"
#include "autoPtr.H"
#include "cellSet.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                           Class evaluateFluctuations Declaration
\*---------------------------------------------------------------------------*/

class evaluateFluctuations
:
    public forceModel
{
private:
    dictionary propsDict_;

    bool interpolate_;

    // evaluate fluctuations only in region
    word activeCellsName_;

    autoPtr<cellSet> activeCells_;
    
    bool allActiveCells_;

    word voidfractionFieldName_;

    const volScalarField& voidfraction_;

    mutable volScalarField voidfractionTest_;

    word voidfractionRecFieldName_;

    const volScalarField& voidfractionRec_;

    scalar critVoidfraction_;

    const scalar dtDEM_;

    bool activeCell(label) const;

public:

    //- Runtime type information
    TypeName("evaluateFluctuations");


    // Constructors

        //- Construct from components
        evaluateFluctuations
        (
            const dictionary& dict,
            cfdemCloud& sm
        );

    // Destructor

        ~evaluateFluctuations();


    // Member Functions
        void setForce() const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
