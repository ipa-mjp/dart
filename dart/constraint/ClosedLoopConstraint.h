/*
 * Copyright (c) 2011-2013, Georgia Tech Research Corporation
 * All rights reserved.
 *
 * Author(s): Karen Liu
 * Date:
 *
 * Georgia Tech Graphics Lab and Humanoid Robotics Lab
 *
 * Directed by Prof. C. Karen Liu and Prof. Mike Stilman
 * <karenliu@cc.gatech.edu> <mstilman@cc.gatech.edu>
 *
 * This file is provided under the following "BSD-style" License:
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DART_CONSTRAINT_CLOSEDLOOPCONSTRAINT_H_
#define DART_CONSTRAINT_CLOSEDLOOPCONSTRAINT_H_

#include <vector>

#include "dart/constraint/Constraint.h"

namespace dart {
namespace dynamics {
class BodyNode;
class Skeleton;
}  // namespace dynamics
}  // namespace dart

namespace dart {
namespace constraint {

/// \brief
class ClosedLoopConstraint : public Constraint
{
public:
  /// \brief
  ClosedLoopConstraint(dynamics::BodyNode *_body1, dynamics::BodyNode *_body2,
                       const Eigen::Vector3d& _offset1,
                       const Eigen::Vector3d& _offset2,
                       int _skelIndex1, int _skelIndex2);

  /// \brief
  virtual ~ClosedLoopConstraint();

  /// \brief
  virtual void updateDynamics(std::vector<Eigen::MatrixXd>* _J,
                              Eigen::VectorXd* _C,
                              Eigen::VectorXd* _CDot,
                              int _rowIndex);

private:
  /// \brief
  void getJacobian();

  /// \brief
  dynamics::BodyNode* mBody1;

  /// \brief
  dynamics::BodyNode* mBody2;

  /// \brief
  Eigen::Vector3d mOffset1;

  /// \brief
  Eigen::Vector3d mOffset2;

  /// \brief
  Eigen::MatrixXd mJ1;

  /// \brief
  Eigen::MatrixXd mJ2;

  /// \brief
  int mSkelIndex1;

  /// \brief
  int mSkelIndex2;
};

}  // namespace constraint
}  // namespace dart

#endif  // DART_CONSTRAINT_CLOSEDLOOPCONSTRAINT_H_