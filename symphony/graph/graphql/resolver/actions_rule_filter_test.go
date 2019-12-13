// Copyright (c) 2004-present Facebook All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package resolver

import (
	"testing"

	"github.com/facebookincubator/symphony/cloud/actions/core"
	"github.com/facebookincubator/symphony/graph/graphql/models"
	"github.com/stretchr/testify/assert"
)

func TestActionsRuleOperator(t *testing.T) {
	r, ctx := actionsContext(t)

	filter := &core.ActionsRuleFilter{
		FilterID:   "filter1",
		OperatorID: "is-string",
		Data:       "testdata",
	}
	res, err := r.ActionsRuleFilter().Operator(ctx, filter)
	assert.NoError(t, err)

	assert.Equal(t, res.OperatorID, core.OperatorIsString.OperatorID())
	assert.Equal(t, res.Description, core.OperatorIsString.Description())
	assert.Equal(t, res.DataType, models.ActionsDataType(core.OperatorIsString.DataType()))

}
