/**
 * Copyright (c) 2021 OceanBase
 * OceanBase CE is licensed under Mulan PubL v2.
 * You can use this software according to the terms and conditions of the Mulan PubL v2.
 * You may obtain a copy of Mulan PubL v2 at:
 *          http://license.coscl.org.cn/MulanPubL-2.0
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PubL v2 for more details.
 */

#ifndef _OB_SQL_EXPR_COALESCE_H_
#define _OB_SQL_EXPR_COALESCE_H_

#include "sql/engine/expr/ob_expr_operator.h"

namespace oceanbase
{
namespace sql
{
class ObExprCoalesce : public ObExprOperator
{
public:
  explicit  ObExprCoalesce(common::ObIAllocator &alloc);
  virtual ~ObExprCoalesce();
  virtual int calc_result_typeN(ObExprResType &type,
                                ObExprResType *types_stack,
                                int64_t param_num,
                                common::ObExprTypeCtx &type_ctx) const;
  virtual int cg_expr(ObExprCGCtx &expr_ct_ctx, const ObRawExpr &raw_expr,
                      ObExpr &rt_expr) const override;
  static int calc_batch_coalesce_expr(const ObExpr &expr, ObEvalCtx &ctx,
                                      const ObBitVector &skip, const int64_t batch_size);
  DECLARE_SET_LOCAL_SESSION_VARS;
private:
  DISALLOW_COPY_AND_ASSIGN(ObExprCoalesce);
};
}
}
#endif /* _OB_SQL_EXPR_COALESCE_H_ */
