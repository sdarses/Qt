/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qbuiltintypes_p.h"

#include "qpaircontainer_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

PairContainer::PairContainer(const Expression::Ptr &operand1,
                             const Expression::Ptr &operand2) : m_operand1(operand1),
                                                                m_operand2(operand2)
{
    Q_ASSERT(m_operand1);
    Q_ASSERT(m_operand2);
}

Expression::List PairContainer::operands() const
{
    Expression::List list;
    list.append(m_operand1);
    list.append(m_operand2);
    return list;
}

void PairContainer::setOperands(const Expression::List &ops)
{
    Q_ASSERT(ops.count() == 2);
    m_operand1 = ops.first();
    m_operand2 = ops.last();
    Q_ASSERT(m_operand1);
    Q_ASSERT(m_operand2);
}

bool PairContainer::compressOperands(const StaticContext::Ptr &context)
{
    Q_ASSERT(m_operand1);
    Q_ASSERT(m_operand2);
    rewrite(m_operand1, m_operand1->compress(context), context);
    rewrite(m_operand2, m_operand2->compress(context), context);

    return m_operand1->isEvaluated() && m_operand2->isEvaluated();
}

QT_END_NAMESPACE
