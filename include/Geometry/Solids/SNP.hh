#ifndef B1SNP_h
#define B1SNP_h 1

#include "G4VSolid.hh"

class SNP: public G4VSolid {
    public:
        SNP(G4String,G4double);
        ~SNP();

        EInside Inside(const G4ThreeVector& p) const override;
        G4ThreeVector SurfaceNormal(const G4ThreeVector& p) const override;
        G4double DistanceToIn(const G4ThreeVector& p, const G4ThreeVector& v) const override;
        G4double DistanceToIn(const G4ThreeVector& p) const override;
        G4double DistanceToOut(const G4ThreeVector& p, const G4ThreeVector& v,
                            const G4bool calcNorm=false, G4bool *validNorm=nullptr, 
                            G4ThreeVector *n=nullptr) const override;
        G4double DistanceToOut(const G4ThreeVector& p) const override;
        void ComputeDimensions(G4VPVParameterisation* p, const G4int n,
                            const G4VPhysicalVolume* pRep) override;
        
        G4GeometryType GetEntityType() const override;
        G4VSolid* Clone() const override;
        std::ostream& StreamInfo(std::ostream& os) const override;
        void DescribeYourselfTo (G4VGraphicsScene &scene) const override;

        G4bool 	CalculateExtent (const EAxis pAxis, const G4VoxelLimits &pVoxelLimit, const G4AffineTransform &pTransform, G4double &pMin, G4double &pMax) const override;
        G4ThreeVector GetPointOnSurface () const override;
        void BoundingLimits(G4ThreeVector& pMin, G4ThreeVector& pMax) const override;



    private:
        G4VSolid* fActualShape = nullptr;
};

#endif