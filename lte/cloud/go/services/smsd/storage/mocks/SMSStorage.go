/*
 *  Copyright 2020 The Magma Authors.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree.
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

// Code generated by mockery v1.0.0. DO NOT EDIT.

package mocks

import (
	storage "magma/lte/cloud/go/services/smsd/storage"

	mock "github.com/stretchr/testify/mock"

	time "time"
)

// SMSStorage is an autogenerated mock type for the SMSStorage type
type SMSStorage struct {
	mock.Mock
}

// CreateSMS provides a mock function with given fields: sms
func (_m *SMSStorage) CreateSMS(sms storage.MutableSMS) (string, error) {
	ret := _m.Called(sms)

	var r0 string
	if rf, ok := ret.Get(0).(func(storage.MutableSMS) string); ok {
		r0 = rf(sms)
	} else {
		r0 = ret.Get(0).(string)
	}

	var r1 error
	if rf, ok := ret.Get(1).(func(storage.MutableSMS) error); ok {
		r1 = rf(sms)
	} else {
		r1 = ret.Error(1)
	}

	return r0, r1
}

// DeleteSMSs provides a mock function with given fields: pks
func (_m *SMSStorage) DeleteSMSs(pks []string) error {
	ret := _m.Called(pks)

	var r0 error
	if rf, ok := ret.Get(0).(func([]string) error); ok {
		r0 = rf(pks)
	} else {
		r0 = ret.Error(0)
	}

	return r0
}

// GetSMSs provides a mock function with given fields: imsis, onlyWaiting, startTime, endTime
func (_m *SMSStorage) GetSMSs(imsis []string, onlyWaiting bool, startTime *time.Time, endTime *time.Time) ([]*storage.SMS, error) {
	ret := _m.Called(imsis, onlyWaiting, startTime, endTime)

	var r0 []*storage.SMS
	if rf, ok := ret.Get(0).(func([]string, bool, *time.Time, *time.Time) []*storage.SMS); ok {
		r0 = rf(imsis, onlyWaiting, startTime, endTime)
	} else {
		if ret.Get(0) != nil {
			r0 = ret.Get(0).([]*storage.SMS)
		}
	}

	var r1 error
	if rf, ok := ret.Get(1).(func([]string, bool, *time.Time, *time.Time) error); ok {
		r1 = rf(imsis, onlyWaiting, startTime, endTime)
	} else {
		r1 = ret.Error(1)
	}

	return r0, r1
}

// GetSMSsToDeliver provides a mock function with given fields: imsis, timeoutThreshold
func (_m *SMSStorage) GetSMSsToDeliver(imsis []string, timeoutThreshold time.Duration) ([]*storage.SMS, error) {
	ret := _m.Called(imsis, timeoutThreshold)

	var r0 []*storage.SMS
	if rf, ok := ret.Get(0).(func([]string, time.Duration) []*storage.SMS); ok {
		r0 = rf(imsis, timeoutThreshold)
	} else {
		if ret.Get(0) != nil {
			r0 = ret.Get(0).([]*storage.SMS)
		}
	}

	var r1 error
	if rf, ok := ret.Get(1).(func([]string, time.Duration) error); ok {
		r1 = rf(imsis, timeoutThreshold)
	} else {
		r1 = ret.Error(1)
	}

	return r0, r1
}

// Init provides a mock function with given fields:
func (_m *SMSStorage) Init() error {
	ret := _m.Called()

	var r0 error
	if rf, ok := ret.Get(0).(func() error); ok {
		r0 = rf()
	} else {
		r0 = ret.Error(0)
	}

	return r0
}

// ReportDelivery provides a mock function with given fields: deliveredMessages, failedMessages
func (_m *SMSStorage) ReportDelivery(deliveredMessages map[string][]byte, failedMessages map[string][]storage.SMSFailureReport) error {
	ret := _m.Called(deliveredMessages, failedMessages)

	var r0 error
	if rf, ok := ret.Get(0).(func(map[string][]byte, map[string][]storage.SMSFailureReport) error); ok {
		r0 = rf(deliveredMessages, failedMessages)
	} else {
		r0 = ret.Error(0)
	}

	return r0
}